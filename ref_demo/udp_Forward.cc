#include <iostream>  
#include <thread>  
#include <vector>  
#include <boost/asio.hpp>  
  
using boost::asio::ip::udp;  
//发送到127.0.0.1::10001
//接收127.0.0.1::10002
// 用于存储接收到的数据的容器  
std::vector<char> recv_buffer(1024);  
  // UDP发送函数  
void send(udp::socket& socket, const udp::endpoint& destination, const std::string& message) {  

    try {  
        socket.send_to(boost::asio::buffer(message), destination);  
        std::cout << "Send Success"<< std::endl;  
    } catch (std::exception& e) {  
        std::cerr << "Send error: " << e.what() << std::endl;  
    }  
}
// UDP接收函数
void receive(udp::socket &socket)
{
    try
    {
        for (;;)
        { // 无限循环，持续接收数据
            std::array<char, 1024> recv_buffer;
            udp::endpoint sender_endpoint;
            size_t len = socket.receive_from(
                boost::asio::buffer(recv_buffer), sender_endpoint);
            std::cout << "Received " << len << " bytes from " << sender_endpoint << std::endl;
            // 将接收到的数据转换为C风格的字符串并打印
            std::string message(recv_buffer.begin(), recv_buffer.begin() + len);
            using boost::asio::ip::address_v4;
            address_v4 send_address = address_v4::from_string("127.0.0.1");
            udp::endpoint destination(send_address, 10002);
            std::cout << "Message: " << message << std::endl;
            send(socket, destination,message);
            //sleep(1);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error in receiver thread: " << e.what() << std::endl;
    }
}

void receive2(udp::socket &socket)
{
    try
    {
        for (;;)
        { // 无限循环，持续接收数据
            std::array<char, 1024> recv_buffer;
            udp::endpoint sender_endpoint;
            size_t len = socket.receive_from(
                boost::asio::buffer(recv_buffer), sender_endpoint);
            std::cout << "Received " << len << " bytes from " << sender_endpoint << std::endl;
            // 将接收到的数据转换为C风格的字符串并打印
            std::string message(recv_buffer.begin(), recv_buffer.begin() + len);
            using boost::asio::ip::address_v4;
            address_v4 send_address = address_v4::from_string("127.0.0.1");
            udp::endpoint destination(send_address, 10001);
            std::cout << "Message: " << message << std::endl;
            send(socket, destination,message);
            //sleep(1);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error in receiver thread: " << e.what() << std::endl;
    }
}


int main()
{
    using boost::asio::ip::udp;

    using boost::asio::ip::address_v4;

    try {  
        boost::asio::io_service io_service;  
        boost::asio::io_service io_service2;
        // 创建UDP1套接字  
        address_v4 receiver_address = address_v4::from_string("127.0.0.1");
        udp::endpoint bind_endpoint(receiver_address, 10003);  
        udp::socket socket(io_service, bind_endpoint); 
        // 创建UDP2套接字  
        address_v4 receiver_address2 = address_v4::from_string("127.0.0.1");
        udp::endpoint bind_endpoint2(receiver_address2, 10004);  
        udp::socket socket2(io_service2, bind_endpoint2); 
        // 输出绑定的本地端点信息  
        udp::endpoint local_endpoint = socket.local_endpoint();
        udp::endpoint local_endpoint2 = socket2.local_endpoint();   
        std::cout << "Listening on UDP endpoint: " << local_endpoint << std::endl;  
        std::cout << "Listening on UDP endpoint2: " << local_endpoint2 << std::endl;  
        // 创建接收线程
        std::thread Forward1_thread([&]()   { receive(socket); });
        std::thread Forward2_thread([&]()   { receive2(socket2); });

        // 等待一段时间以接收响应或进行其他操作  
        //std::this_thread::sleep_for(std::chrono::seconds(5));  
  
        // 停止接收线程（实际上，在这个例子中，我们不会停止它，因为它是一个无限循环）  
        // 在实际应用中，您可能需要一种机制来优雅地停止接收线程  
  
        // 等待接收线程完成（如果使用了停止机制，则取消注释以下行）  

        Forward1_thread.join();
        Forward2_thread.join();
    } catch (std::exception& e) {  
        std::cerr << "Exception: " << e.what() << std::endl;  
    }  
    
    return 0;
}
