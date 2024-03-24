#include <iostream>  
#include <thread>  
#include <vector>  
#include <cstring>  
#include <unistd.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
  
const int BUFFER_SIZE = 1024;  
const int PORT = 12345; // 转发器监听的端口  
  
struct Client {  
    int socket;  
    struct sockaddr_in addr;  
    socklen_t addr_len;  
};  
  
void forwardMessages(Client& fromClient, Client& toClient) {  
    char buffer[BUFFER_SIZE];  
    while (true) {  
        int bytesRead = recvfrom(fromClient.socket, buffer, BUFFER_SIZE, 0, nullptr, nullptr);  
        if (bytesRead <= 0) {  
            break; // 连接关闭或出错  
        }  
          
        sendto(toClient.socket, buffer, bytesRead, 0, (struct sockaddr*)&toClient.addr, toClient.addr_len);  
    }  
      
    close(fromClient.socket);  
}  
  
int main() {  
    int serverSocket, clientSocket;  
    struct sockaddr_in serverAddr, clientAddr;  
    socklen_t clientAddrLen;  
    Client clients[2];  
    std::vector<std::thread> threads;  
  
    // 创建UDP socket  
    if ((serverSocket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {  
        perror("socket creation failed");  
        return -1;  
    }  
  
    // 绑定socket到指定端口  
    memset(&serverAddr, 0, sizeof(serverAddr));  
    serverAddr.sin_family = AF_INET;  
    serverAddr.sin_addr.s_addr = INADDR_ANY;  
    serverAddr.sin_port = htons(PORT);  
      
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {  
        perror("bind failed");  
        return -1;  
    }  
  
    // 等待并接受两个客户端的连接  
    std::cout << "Waiting for two clients to connect..." << std::endl;  
    for (int i = 0; i < 2; ++i) {  
        clientAddrLen = sizeof(clientAddr);  
        if ((clientSocket = recvfrom(serverSocket, nullptr, 0, MSG_DONTWAIT, (struct sockaddr*)&clientAddr, &clientAddrLen)) < 0) {  
            if (errno == EWOULDBLOCK || errno == EAGAIN) {  
                continue; // 非阻塞接收，没有数据则继续等待  
            }  
            perror("recvfrom failed");  
            return -1;  
        }  
          
        clients[i].socket = clientSocket;  
        clients[i].addr = clientAddr;  
        clients[i].addr_len = clientAddrLen;  
        std::cout << "Client " << i + 1 << " connected." << std::endl;  
    }  
  
    std::cout << "Clients connected. Forwarding messages..." << std::endl;  
    // 创建两个线程分别处理转发任务  
    threads.push_back(std::thread(forwardMessages, std::ref(clients[0]), std::ref(clients[1])));  
    threads.push_back(std::thread(forwardMessages, std::ref(clients[1]), std::ref(clients[0])));  
  
    // 等待线程结束  
    for (auto& thread : threads) {  
        thread.join();  
    }  
  
    close(serverSocket);  
    return 0;  
}