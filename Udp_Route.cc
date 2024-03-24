#include <arpa/inet.h>
#include <boost/asio.hpp>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>
#include <vector>
using boost::asio::ip::udp;

#define ROUTE_PORT 2152
#define ROUTE_IP "127.0.100.88"

#define EPC_PORT 2152
#define EPC_IP "127.0.100.2"

#define ENB_PORT 2152
#define ENB_IP "127.0.100.3"

struct Client {
  struct sockaddr_in addr;
  socklen_t          addr_len;
};
int num=0;
void routeMessage(Client* client, int route_fd)
{
  struct sockaddr_in from_addr;
  socklen_t          from_len = sizeof(from_addr);
  unsigned char      buffer[1500];

  while (1) {
    int bytes = recvfrom(route_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&(from_addr), &(from_len));
    if (bytes <= 0) {
      printf("recvfrom error");
      break;
    }
 //printf("index: %d \n",num++);
    // 打印收到的消息
    printf("Received message from %s:%d\n", inet_ntoa(from_addr.sin_addr), ntohs(from_addr.sin_port));
    // printf("buffer = %s\n", buffer);

    //
    Client toClient = (from_addr.sin_addr.s_addr == inet_addr(EPC_IP)) ? client[1] : client[0];

    // 发送给对应的client
    printf("Send message to %s:%d \n", inet_ntoa(toClient.addr.sin_addr), ntohs(toClient.addr.sin_port));
    sendto(route_fd, buffer, bytes, 0, (struct sockaddr*)&(toClient.addr), toClient.addr_len);
  }
}
int main()
{
  // route config
  int route_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (route_fd < 0) {
    printf("socket error");
    return -1;
  }

  struct sockaddr_in route_addr;
  memset(&route_addr, 0, sizeof(route_addr));
  route_addr.sin_family      = AF_INET;
  route_addr.sin_port        = htons(ROUTE_PORT);
  route_addr.sin_addr.s_addr = inet_addr(ROUTE_IP);

  if (bind(route_fd, (struct sockaddr*)&route_addr, sizeof(route_addr)) < 0) {
    printf("bind route error");
    return -1;
  }
  // Client config  , client[0] is EPC,   client[1] is ENB
  Client client[2];
  client[0].addr.sin_family      = AF_INET;
  client[0].addr.sin_port        = htons(EPC_PORT);
  client[0].addr.sin_addr.s_addr = inet_addr(EPC_IP);
  client[0].addr_len             = sizeof(client[0].addr);

  client[1].addr.sin_family      = AF_INET;
  client[1].addr.sin_port        = htons(ENB_PORT);
  client[1].addr.sin_addr.s_addr = inet_addr(ENB_IP);
  client[1].addr_len             = sizeof(client[1].addr);

  routeMessage(client, route_fd);

  close(route_fd);

  return 0;
}
