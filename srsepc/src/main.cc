/**
 * Copyright 2013-2023 Software Radio Systems Limited
 *
 * This file is part of srsRAN.
 *
 * srsRAN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsRAN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#include "srsepc/hdr/hss/hss.h"
#include "srsepc/hdr/mme/mme.h"
#include "srsepc/hdr/spgw/spgw.h"
#include "srsran/build_info.h"
#include "srsran/common/bcd_helpers.h"
#include "srsran/common/common_helper.h"
#include "srsran/common/config_file.h"
#include "srsran/common/crash_handler.h"
#include "srsran/srslog/srslog.h"
#include "srsran/srsran.h"
#include "srsran/support/emergency_handlers.h"
#include "srsran/support/signal_handler.h"
#include <arpa/inet.h>
#include <boost/program_options.hpp>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
//-----------------------------------------------------------------------
#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <vector>
//-------------------------------------------------------------------------

#define EPC_PORT 1111
#define EPC_IP "127.0.0.1"
#define ROUTE_PORT 8888
#define ROUTE_IP "127.0.0.8"

using namespace std;
using namespace srsepc;
namespace bpo = boost::program_options;
//-----------------------------------------------------------------------------
using boost::asio::ip::udp;
// 接收 127.0.0.1::10001
// 发送 127.0.0.1::10002
// 用于存储接收到的数据的容器
std::vector<char> recv_buffer(1024);

// UDP接收函数
void receive(udp::socket& socket)
{
  try {
    for (;;) { // 无限循环，持续接收数据
      std::array<char, 1024> recv_buffer;
      udp::endpoint          sender_endpoint;
      size_t                 len = socket.receive_from(boost::asio::buffer(recv_buffer), sender_endpoint);
      std::cout << "Received " << len << " bytes from " << sender_endpoint << std::endl;
      // 将接收到的数据转换为C风格的字符串并打印
      std::string message(recv_buffer.begin(), recv_buffer.begin() + len);
      std::cout << "Receive Message: " << message << std::endl;
    }
  } catch (std::exception& e) {
    std::cerr << "Error in receiver thread: " << e.what() << std::endl;
  }
}

// UDP发送函数
void send(udp::socket& socket, const udp::endpoint& destination, const std::string& message)
{
  try {
    socket.send_to(boost::asio::buffer(message), destination);
    std::cout << "Send Success" << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Send error: " << e.what() << std::endl;
  }
}
//------------------------------------------------------------------------------------------------------

typedef struct {
  std::string nas_level;
  int         nas_hex_limit;
  std::string s1ap_level;
  int         s1ap_hex_limit;
  std::string mme_gtpc_level;
  int         mme_gtpc_hex_limit;
  std::string spgw_gtpc_level;
  int         spgw_gtpc_hex_limit;
  std::string gtpu_level;
  int         gtpu_hex_limit;
  std::string spgw_level;
  int         spgw_hex_limit;
  std::string hss_level;
  int         hss_hex_limit;
  std::string all_level;
  int         all_hex_limit;
  std::string filename;
} log_args_t;

typedef struct {
  mme_args_t  mme_args;
  hss_args_t  hss_args;
  spgw_args_t spgw_args;
  log_args_t  log_args;
} all_args_t;

static srslog::sink*     log_sink = nullptr;
static std::atomic<bool> running  = {true};

/**********************************************************************
 *  Program arguments processing
 ***********************************************************************/
string config_file;

void parse_args(all_args_t* args, int argc, char* argv[])
{
  string   mme_name;
  string   mme_code;
  string   mme_group;
  string   tac;
  string   mcc;
  string   mnc;
  string   mme_bind_addr;
  string   mme_apn;
  string   encryption_algo;
  string   integrity_algo;
  uint16_t paging_timer     = 0;
  uint32_t max_paging_queue = 0;
  string   spgw_bind_addr;
  string   sgi_if_addr;
  string   sgi_if_name;
  string   dns_addr;
  string   full_net_name;
  string   short_net_name;
  bool     request_imeisv;
  string   hss_db_file;
  string   hss_auth_algo;
  string   log_filename;
  string   lac;

  // Command line only options
  bpo::options_description general("General options");
  // clang-format off
  general.add_options()
      ("help,h", "Produce help message")
      ("version,v", "Print version information and exit")
      ;

  // Command line or config file options
  bpo::options_description common("Configuration options");
  common.add_options()
    ("mme.mme_code",        bpo::value<string>(&mme_code)->default_value("0x01"),            "MME Code")
    ("mme.name",            bpo::value<string>(&mme_name)->default_value("srsmme01"),        "MME Name")
    ("mme.mme_group",       bpo::value<string>(&mme_group)->default_value("0x01"),           "Cell ID")
    ("mme.tac",             bpo::value<string>(&tac)->default_value("0x0"),                  "Tracking Area Code")
    ("mme.mcc",             bpo::value<string>(&mcc)->default_value("001"),                  "Mobile Country Code")
    ("mme.mnc",             bpo::value<string>(&mnc)->default_value("01"),                   "Mobile Network Code")
    ("mme.mme_bind_addr",   bpo::value<string>(&mme_bind_addr)->default_value("127.0.0.1"),  "IP address of MME for S1 connection")
    ("mme.dns_addr",        bpo::value<string>(&dns_addr)->default_value("8.8.8.8"),         "IP address of the DNS server for the UEs")
    ("mme.full_net_name",   bpo::value<string>(&full_net_name)->default_value("Software Radio Systems RAN"), "Full name of the network")
    ("mme.short_net_name",  bpo::value<string>(&short_net_name)->default_value("srsRAN"),    "Short name of the network")
    ("mme.apn",             bpo::value<string>(&mme_apn)->default_value(""),                 "Set Access Point Name (APN) for data services")
    ("mme.encryption_algo", bpo::value<string>(&encryption_algo)->default_value("EEA0"),     "Set preferred encryption algorithm for NAS layer ")
    ("mme.integrity_algo",  bpo::value<string>(&integrity_algo)->default_value("EIA1"),      "Set preferred integrity protection algorithm for NAS")
    ("mme.paging_timer",    bpo::value<uint16_t>(&paging_timer)->default_value(2),           "Set paging timer value in seconds (T3413)")
    ("mme.request_imeisv",  bpo::value<bool>(&request_imeisv)->default_value(false),         "Enable IMEISV request in Security mode command")
    ("mme.lac",             bpo::value<string>(&lac)->default_value("0x01"),                 "Location Area Code")
    ("hss.db_file",         bpo::value<string>(&hss_db_file)->default_value("ue_db.csv"),    ".csv file that stores UE's keys")
    ("spgw.gtpu_bind_addr", bpo::value<string>(&spgw_bind_addr)->default_value("127.0.0.1"), "IP address of SP-GW for the S1-U connection")
    ("spgw.sgi_if_addr",    bpo::value<string>(&sgi_if_addr)->default_value("176.16.0.1"),   "IP address of TUN interface for the SGi connection")
    ("spgw.sgi_if_name",    bpo::value<string>(&sgi_if_name)->default_value("srs_spgw_sgi"), "Name of TUN interface for the SGi connection")
    ("spgw.max_paging_queue", bpo::value<uint32_t>(&max_paging_queue)->default_value(100), "Max number of packets in paging queue")

    ("pcap.enable",   bpo::value<bool>(&args->mme_args.s1ap_args.pcap_enable)->default_value(false),         "Enable S1AP PCAP")
    ("pcap.filename", bpo::value<string>(&args->mme_args.s1ap_args.pcap_filename)->default_value("/tmp/epc.pcap"), "PCAP filename")

    ("log.nas_level",           bpo::value<string>(&args->log_args.nas_level),        "MME NAS  log level")
    ("log.nas_hex_limit",       bpo::value<int>(&args->log_args.nas_hex_limit),       "MME NAS log hex dump limit")
    ("log.s1ap_level",          bpo::value<string>(&args->log_args.s1ap_level),       "MME S1AP log level")
    ("log.s1ap_hex_limit",      bpo::value<int>(&args->log_args.s1ap_hex_limit),      "MME S1AP log hex dump limit")
    ("log.mme_gtpc_level",      bpo::value<string>(&args->log_args.mme_gtpc_level),   "MME GTPC log level")
    ("log.mme_gtpc_hex_limit",  bpo::value<int>(&args->log_args.mme_gtpc_hex_limit),  "MME GTPC log hex dump limit")
    ("log.spgw_gtpc_level",     bpo::value<string>(&args->log_args.spgw_gtpc_level),  "SPGW GTPC log level")
    ("log.spgw_gtpc_hex_limit", bpo::value<int>(&args->log_args.spgw_gtpc_hex_limit), "SPGW GTPC log hex dump limit")
    ("log.gtpu_level",          bpo::value<string>(&args->log_args.gtpu_level),       "GTP-U log level")
    ("log.gtpu_hex_limit",      bpo::value<int>(&args->log_args.gtpu_hex_limit),      "GTP-U log hex dump limit")
    ("log.spgw_level",          bpo::value<string>(&args->log_args.spgw_level),       "SPGW log level")
    ("log.spgw_hex_limit",      bpo::value<int>(&args->log_args.spgw_hex_limit),      "SPGW log hex dump limit")
    ("log.hss_level",           bpo::value<string>(&args->log_args.hss_level),        "HSS log level")
    ("log.hss_hex_limit",       bpo::value<int>(&args->log_args.hss_hex_limit),       "HSS log hex dump limit")

    ("log.all_level",     bpo::value<string>(&args->log_args.all_level)->default_value("info"),   "ALL log level")
    ("log.all_hex_limit", bpo::value<int>(&args->log_args.all_hex_limit)->default_value(32),  "ALL log hex dump limit")

    ("log.filename", bpo::value<string>(&args->log_args.filename)->default_value("/tmp/epc.log"),"Log filename")
    ;

  // Positional options - config file location
  bpo::options_description position("Positional options");
  position.add_options()
    ("config_file", bpo::value< string >(&config_file), "MME configuration file")
  ;
  // clang-format on

  bpo::positional_options_description p;
  p.add("config_file", -1);

  // these options are allowed on the command line
  bpo::options_description cmdline_options;
  cmdline_options.add(common).add(position).add(general);

  // parse the command line and store result in vm
  bpo::variables_map vm;
  try {
    bpo::store(bpo::command_line_parser(argc, argv).options(cmdline_options).positional(p).run(), vm);
    bpo::notify(vm);
  } catch (bpo::error& e) {
    cerr << e.what() << endl;
    exit(1);
  }

  // help option was given - print usage and exit
  if (vm.count("help")) {
    cout << "Usage: " << argv[0] << " [OPTIONS] config_file" << endl << endl;
    cout << common << endl << general << endl;
    exit(0);
  }

  // if no config file given, check users home path
  if (!vm.count("config_file")) {
    if (!config_exists(config_file, "epc.conf")) {
      cout << "Failed to read EPC configuration file " << config_file << " - exiting" << endl;
      exit(1);
    }
  }

  // Parsing Config File
  cout << "Reading configuration file " << config_file << "..." << endl;
  ifstream conf(config_file.c_str(), ios::in);
  if (conf.fail()) {
    cout << "Failed to read configuration file " << config_file << " - exiting" << endl;
    exit(1);
  }
  // parse config file and handle errors gracefully
  try {
    bpo::store(bpo::parse_config_file(conf, common), vm);
    bpo::notify(vm);
  } catch (const boost::program_options::error& e) {
    cerr << e.what() << endl;
    exit(1);
  }

  // Convert hex strings
  {
    std::stringstream sstr;
    sstr << std::hex << vm["mme.mme_group"].as<std::string>();
    sstr >> args->mme_args.s1ap_args.mme_group;
  }
  {
    std::stringstream sstr;
    sstr << std::hex << vm["mme.mme_code"].as<std::string>();
    uint16_t tmp; // Need intermediate uint16_t as uint8_t is treated as char
    sstr >> tmp;
    args->mme_args.s1ap_args.mme_code = tmp;
  }
  args->mme_args.s1ap_args.tac = std::stoi(vm["mme.tac"].as<std::string>(), nullptr, 0);
  args->mme_args.s1ap_args.lac = std::stoi(vm["mme.lac"].as<std::string>(), nullptr, 0);

  // Convert MCC/MNC strings
  if (!srsran::string_to_mcc(mcc, &args->mme_args.s1ap_args.mcc)) {
    cout << "Error parsing mme.mcc:" << mcc << " - must be a 3-digit string." << endl;
  }
  if (!srsran::string_to_mnc(mnc, &args->mme_args.s1ap_args.mnc)) {
    cout << "Error parsing mme.mnc:" << mnc << " - must be a 2 or 3-digit string." << endl;
  }

  // Convert MCC/MNC strings
  if (!srsran::string_to_mcc(mcc, &args->hss_args.mcc)) {
    cout << "Error parsing mme.mcc:" << mcc << " - must be a 3-digit string." << endl;
  }
  if (!srsran::string_to_mnc(mnc, &args->hss_args.mnc)) {
    cout << "Error parsing mme.mnc:" << mnc << " - must be a 2 or 3-digit string." << endl;
  }

  std::transform(encryption_algo.begin(), encryption_algo.end(), encryption_algo.begin(), ::tolower);
  if (encryption_algo == "eea0") {
    args->mme_args.s1ap_args.encryption_algo = srsran::CIPHERING_ALGORITHM_ID_EEA0;
  } else if (encryption_algo == "eea1") {
    args->mme_args.s1ap_args.encryption_algo = srsran::CIPHERING_ALGORITHM_ID_128_EEA1;
  } else if (encryption_algo == "eea2") {
    args->mme_args.s1ap_args.encryption_algo = srsran::CIPHERING_ALGORITHM_ID_128_EEA2;
  } else if (encryption_algo == "eea3") {
    args->mme_args.s1ap_args.encryption_algo = srsran::CIPHERING_ALGORITHM_ID_128_EEA3;
  } else {
    args->mme_args.s1ap_args.encryption_algo = srsran::CIPHERING_ALGORITHM_ID_EEA0;
    cout << "Error parsing mme.encryption_algo:" << encryption_algo << " - must be EEA0, EEA1, EEA2 or EEA3." << endl;
    cout << "Using default mme.encryption_algo: EEA0" << endl;
  }

  std::transform(integrity_algo.begin(), integrity_algo.end(), integrity_algo.begin(), ::tolower);
  if (integrity_algo == "eia0") {
    args->mme_args.s1ap_args.integrity_algo = srsran::INTEGRITY_ALGORITHM_ID_EIA0;
    cout << "Warning parsing mme.integrity_algo:" << encryption_algo
         << " - EIA0 will not supported by UEs use EIA1 or EIA2" << endl;
  } else if (integrity_algo == "eia1") {
    args->mme_args.s1ap_args.integrity_algo = srsran::INTEGRITY_ALGORITHM_ID_128_EIA1;
  } else if (integrity_algo == "eia2") {
    args->mme_args.s1ap_args.integrity_algo = srsran::INTEGRITY_ALGORITHM_ID_128_EIA2;
  } else if (integrity_algo == "eia3") {
    args->mme_args.s1ap_args.integrity_algo = srsran::INTEGRITY_ALGORITHM_ID_128_EIA3;
  } else {
    args->mme_args.s1ap_args.integrity_algo = srsran::INTEGRITY_ALGORITHM_ID_128_EIA1;
    cout << "Error parsing mme.integrity_algo:" << encryption_algo << " - must be EIA0, EIA1, EIA2 or EIA3." << endl;
    cout << "Using default mme.integrity_algo: EIA1" << endl;
  }

  args->mme_args.s1ap_args.mme_bind_addr  = mme_bind_addr;
  args->mme_args.s1ap_args.mme_name       = mme_name;
  args->mme_args.s1ap_args.dns_addr       = dns_addr;
  args->mme_args.s1ap_args.full_net_name  = full_net_name;
  args->mme_args.s1ap_args.short_net_name = short_net_name;
  args->mme_args.s1ap_args.mme_apn        = mme_apn;
  args->mme_args.s1ap_args.paging_timer   = paging_timer;
  args->mme_args.s1ap_args.request_imeisv = request_imeisv;
  args->spgw_args.gtpu_bind_addr          = spgw_bind_addr;
  args->spgw_args.sgi_if_addr             = sgi_if_addr;
  args->spgw_args.sgi_if_name             = sgi_if_name;
  args->spgw_args.max_paging_queue        = max_paging_queue;
  args->hss_args.db_file                  = hss_db_file;

  // Apply all_level to any unset layers
  if (vm.count("log.all_level")) {
    if (!vm.count("log.nas_level")) {
      args->log_args.nas_level = args->log_args.all_level;
    }
    if (!vm.count("log.s1ap_level")) {
      args->log_args.s1ap_level = args->log_args.all_level;
    }
    if (!vm.count("log.mme_gtpc_level")) {
      args->log_args.mme_gtpc_level = args->log_args.all_level;
    }
    if (!vm.count("log.spgw_gtpc_level")) {
      args->log_args.spgw_gtpc_level = args->log_args.all_level;
    }
    if (!vm.count("log.gtpu_level")) {
      args->log_args.gtpu_level = args->log_args.all_level;
    }
    if (!vm.count("log.spgw_level")) {
      args->log_args.spgw_level = args->log_args.all_level;
    }
    if (!vm.count("log.hss_level")) {
      args->log_args.hss_level = args->log_args.all_level;
    }
  }

  // Apply all_hex_limit to any unset layers
  if (vm.count("log.all_hex_limit")) {
    if (!vm.count("log.s1ap_hex_limit")) {
      args->log_args.s1ap_hex_limit = args->log_args.all_hex_limit;
    }
    if (!vm.count("log.mme_gtpc_hex_limit")) {
      args->log_args.mme_gtpc_hex_limit = args->log_args.all_hex_limit;
    }
    if (!vm.count("log.spgw_gtpc_hex_limit")) {
      args->log_args.spgw_gtpc_hex_limit = args->log_args.all_hex_limit;
    }
    if (!vm.count("log.gtpu_hex_limit")) {
      args->log_args.gtpu_hex_limit = args->log_args.all_hex_limit;
    }
    if (!vm.count("log.spgw_hex_limit")) {
      args->log_args.spgw_hex_limit = args->log_args.all_hex_limit;
    }
    if (!vm.count("log.hss_hex_limit")) {
      args->log_args.hss_hex_limit = args->log_args.all_hex_limit;
    }
    if (!vm.count("log.nas_hex_limit")) {
      args->log_args.nas_hex_limit = args->log_args.all_hex_limit;
    }
  }

  // Check user database
  if (!config_exists(args->hss_args.db_file, "user_db.csv")) {
    cout << "Failed to read HSS user database file " << args->hss_args.db_file << " - exiting" << endl;
    exit(1);
  }

  return;
}

std::string get_build_mode()
{
  return std::string(srsran_get_build_mode());
}

std::string get_build_info()
{
  if (std::string(srsran_get_build_info()).find("  ") != std::string::npos) {
    return std::string(srsran_get_version());
  }
  return std::string(srsran_get_build_info());
}

std::string get_build_string()
{
  std::stringstream ss;
  ss << "Built in " << get_build_mode() << " mode using " << get_build_info() << "." << std::endl;
  return ss.str();
}

static void emergency_cleanup_handler(void* data)
{
  srslog::flush();
  if (log_sink) {
    log_sink->flush();
  }
}

static void signal_handler()
{
  running = false;
}

int main(int argc, char* argv[])
{
  srsran_register_signal_handler(signal_handler);
  add_emergency_cleanup_handler(emergency_cleanup_handler, nullptr);

  // print build info
  cout << endl << get_build_string() << endl;

  cout << endl << "---  Software Radio Systems EPC  ---" << endl << endl;
  srsran_debug_handle_crash(argc, argv);

  all_args_t args = {};
  parse_args(&args, argc, argv);

  // Setup logging.
  log_sink = (args.log_args.filename == "stdout") ? srslog::create_stdout_sink()
                                                  : srslog::create_file_sink(args.log_args.filename);
  if (!log_sink) {
    return SRSRAN_ERROR;
  }
  srslog::log_channel* chan = srslog::create_log_channel("main_channel", *log_sink);
  if (!chan) {
    return SRSRAN_ERROR;
  }
  srslog::set_default_sink(*log_sink);

  // Start the log backend.
  srslog::init();

  if (args.log_args.filename != "stdout") {
    auto& epc_logger = srslog::fetch_basic_logger("EPC", false);
    epc_logger.info("\n\n%s\n---  Software Radio Systems EPC log ---\n\n", get_build_string().c_str());
  }

  srsran::log_args(argc, argv, "EPC");

  srslog::basic_logger& nas_logger = srslog::fetch_basic_logger("NAS", false);
  nas_logger.set_level(srslog::str_to_basic_level(args.log_args.nas_level));
  nas_logger.set_hex_dump_max_size(args.log_args.nas_hex_limit);

  auto& s1ap_logger = srslog::fetch_basic_logger("S1AP", false);
  s1ap_logger.set_level(srslog::str_to_basic_level(args.log_args.s1ap_level));
  s1ap_logger.set_hex_dump_max_size(args.log_args.s1ap_hex_limit);

  auto& mme_gtpc_logger = srslog::fetch_basic_logger("MME GTPC", false);
  mme_gtpc_logger.set_level(srslog::str_to_basic_level(args.log_args.mme_gtpc_level));
  mme_gtpc_logger.set_hex_dump_max_size(args.log_args.mme_gtpc_hex_limit);

  auto& hss_logger = srslog::fetch_basic_logger("HSS", false);
  hss_logger.set_level(srslog::str_to_basic_level(args.log_args.hss_level));
  hss_logger.set_hex_dump_max_size(args.log_args.hss_hex_limit);

  auto& spgw_gtpc_logger = srslog::fetch_basic_logger("SPGW GTPC", false);
  spgw_gtpc_logger.set_level(srslog::str_to_basic_level(args.log_args.spgw_gtpc_level));
  spgw_gtpc_logger.set_hex_dump_max_size(args.log_args.spgw_gtpc_hex_limit);

  auto& gtpu_logger = srslog::fetch_basic_logger("GTPU", false);
  gtpu_logger.set_level(srslog::str_to_basic_level(args.log_args.gtpu_level));
  gtpu_logger.set_hex_dump_max_size(args.log_args.gtpu_hex_limit);

  auto& spgw_logger = srslog::fetch_basic_logger("SPGW", false);
  spgw_logger.set_level(srslog::str_to_basic_level(args.log_args.spgw_level));
  spgw_logger.set_hex_dump_max_size(args.log_args.spgw_hex_limit);

  hss* hss = hss::get_instance();
  if (hss->init(&args.hss_args)) {
    cout << "Error initializing HSS" << endl;
    exit(1);
  }

  mme* mme = mme::get_instance();
  if (mme->init(&args.mme_args)) {
    cout << "Error initializing MME" << endl;
    exit(1);
  }

  spgw* spgw = spgw::get_instance();
  if (spgw->init(&args.spgw_args, hss->get_ip_to_imsi())) {
    cout << "Error initializing SP-GW" << endl;
    exit(1);
  }

  mme->start();
  spgw->start();

  //-----------------------------------------------------------------------------add
  //UDP---------------------------------------------------------------------------------

  // EPC send to ENB

  // create socket
  int epc_sock = socket(AF_INET, SOCK_DGRAM, 0);
  // bind  my address
  struct sockaddr_in send_addr;
  memset(&send_addr, 0, sizeof(send_addr));
  send_addr.sin_family      = AF_INET;
  send_addr.sin_addr.s_addr = inet_addr(EPC_IP);
  send_addr.sin_port        = htons(EPC_PORT);
  bind(epc_sock, (struct sockaddr*)&send_addr, sizeof(send_addr));
  // set target address
  struct sockaddr_in end_addr;
  memset(&end_addr, 0, sizeof(end_addr));
  end_addr.sin_family      = AF_INET;
  end_addr.sin_addr.s_addr = inet_addr(ROUTE_IP);
  end_addr.sin_port        = htons(ROUTE_PORT);
  // set send data
  char send_data[] = "srsRAN EPC SEND TO ENB TEST";

  //--------------------------------------------------------------------------------------
  // Receive data from ENB

  // set from address
  struct sockaddr_in from_addr;
  socklen_t          len = sizeof(from_addr);
  // set receive buffer
  char buffer[1500] = "";

  // set transmit number
  int num = 0;

  //----------------------------------------------------------------------------------------------------------------------------------------------------------------------

  while (running) {
    /*
    //receive data
    ssize_t rec_id=recvfrom(epc_sock,buffer,sizeof(buffer),0,(struct sockaddr*)&from_addr,&len);
    printf("-----------------------------receiving---------------------------\n");
    printf("index: %d\n",num);
    printf("my ip:\t\t%s:%d\n",inet_ntoa(send_addr.sin_addr), ntohs(send_addr.sin_port));
    printf("source ip :\t%s:%d\n",inet_ntoa(from_addr.sin_addr), ntohs(from_addr.sin_port));
    printf("receive bytes length :\t%zd\n",rec_id);
    printf("receive data is\t%s\n",buffer);
    printf("-----------------------------------------------------------------\n");
    printf("\n");
    printf("\n");

    //send data
    ssize_t send_id=sendto(epc_sock, send_data, strlen(send_data), 0, (struct sockaddr*)&end_addr, sizeof(end_addr));
    printf("-----------------------------sending-----------------------------\n");
    printf("index: %d\n",num);
    printf("my ip:               %s:%d\n",inet_ntoa(send_addr.sin_addr), ntohs(send_addr.sin_port));
    printf("target ip :          %s:%d\n",inet_ntoa(end_addr.sin_addr), ntohs(end_addr.sin_port));
    printf("send bytes length :  %zd\n",send_id);
    printf("send data is         %s\n",send_data);
    printf("-----------------------------------------------------------------\n");
    printf("\n");
    printf("\n");
    num++;
    */
/*
    using boost::asio::ip::udp;

    using boost::asio::ip::address_v4;

    try {
      boost::asio::io_service io_service;

      // 创建UDP套接字
      address_v4    receiver_address = address_v4::from_string("127.0.0.1");
      udp::endpoint bind_endpoint(receiver_address, 10002);
      udp::socket   socket(io_service, bind_endpoint);

      // 输出绑定的本地端点信息
      udp::endpoint local_endpoint = socket.local_endpoint();
      std::cout << "Listening on UDP endpoint: " << local_endpoint << std::endl;
      // 创建接收线程
      std::thread receiver_thread([&]() { receive(socket); });

      address_v4 send_address = address_v4::from_string("127.0.0.1");

      // 假设我们知道要发送到的地址和端口
      udp::endpoint destination(send_address, 10004);

      std::string message;
      std::cout << "Enter the message to send: ";
      std::getline(std::cin, message);
      // 发送一些数据
      std::thread send_thread([&]() {
        for (;;) {
          std::string message;
          std::cout << "Enter the message to send: ";
          std::getline(std::cin, message);

          send(socket, destination, message);
        }
      });

      // 等待一段时间以接收响应或进行其他操作
      // std::this_thread::sleep_for(std::chrono::seconds(5));

      // 停止接收线程（实际上，在这个例子中，我们不会停止它，因为它是一个无限循环）
      // 在实际应用中，您可能需要一种机制来优雅地停止接收线程

      // 等待接收线程完成（如果使用了停止机制，则取消注释以下行）
      receiver_thread.join();
      send_thread.join();
    } catch (std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
*/
    sleep(1);
  }
  close(epc_sock);
  mme->stop();
  mme->cleanup();
  spgw->stop();
  spgw->cleanup();
  hss->stop();
  hss->cleanup();

  cout << std::endl << "---  exiting  ---" << endl;

  return 0;
}
