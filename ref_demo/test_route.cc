#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include<iostream>
#define MAX_BUFFER_SIZE 1500 

#define ROUTE_PORT 2222  
#define ROUTE_IP "10.24.145.5"  

#define DESTINATION_IP "10.24.145.5"  
#define DESTINATION_PORT 4444

int main() {  

     
    // 创建route套接字  
    int route_sock = socket(AF_INET, SOCK_DGRAM, 0);  
    
    // 设置route地址信息  
    struct sockaddr_in route_addr;  
    memset(&route_addr, 0, sizeof(route_addr));  
    route_addr.sin_family = AF_INET;  
    route_addr.sin_addr.s_addr = inet_addr(ROUTE_IP);  
    route_addr.sin_port = htons(ROUTE_PORT);  

    // 绑定route地址信息
    bind(route_sock, (struct sockaddr*)&route_addr, sizeof(route_addr));

    //printf("Listening on %s:%d\n", ROUTE_IP, ROUTE_PORT);  
  
    // 创建转发套接字  
   int  forward_sock = socket(AF_INET, SOCK_DGRAM, 0);  
   struct sockaddr_in route_addr_02;  
    memset(&route_addr_02, 0, sizeof(route_addr_02));  
    route_addr_02.sin_family = AF_INET;  
    route_addr_02.sin_addr.s_addr = inet_addr(ROUTE_IP_2);  
    route_addr_02.sin_port = htons(ROUTE_PORT_2); 
   //bind
   bind(forward_sock, (struct sockaddr*)&route_addr_02, sizeof(route_addr_02));
  
    // 设置转发地址信息  
    struct sockaddr_in forward_addr;
    memset(&forward_addr, 0, sizeof(forward_addr));  
    forward_addr.sin_family = AF_INET;  
    forward_addr.sin_addr.s_addr = inet_addr(DESTINATION_IP);  
    forward_addr.sin_port = htons(DESTINATION_PORT);  
   int num=0;
    while (1) {  
        
    

        // 接收数据  
        char buffer[MAX_BUFFER_SIZE];  
        struct sockaddr_in source_addr;  
        socklen_t source_len = sizeof(source_addr);
      
        ssize_t recv_id = recvfrom(route_sock, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&source_addr, &source_len);  
        
       

        printf("-----------------------------receiving---------------------------\n");
        printf("index: %d\n",num);
        printf("my ip:\t\t%s:%d\n",inet_ntoa(route_addr.sin_addr), ntohs(route_addr.sin_port));
        printf("source ip : \t%s:%d\n",inet_ntoa(source_addr.sin_addr), ntohs(source_addr.sin_port));
        printf("receive bytes length : \t%zd\n",recv_id);
        printf("receive data is \t%s\n",buffer);
        printf("-----------------------------------------------------------------\n");
        printf("\n");
        printf("\n");



        // 转发数据  
         ssize_t  send_id=sendto(forward_sock, buffer, recv_id, 0, (struct sockaddr*)&forward_addr, sizeof(forward_addr));
        
  
        printf("-----------------------------sending-----------------------------\n");
        printf("index: %d\n",num);
        printf("my ip:               %s:%d\n",inet_ntoa(route_addr_02.sin_addr), ntohs(route_addr_02.sin_port));
            printf("target ip :          %s:%d\n",inet_ntoa(forward_addr.sin_addr), ntohs(forward_addr.sin_port));
            printf("send bytes length :  %zd\n",send_id);
            printf("send data is         %s\n",buffer);
        printf("-----------------------------------------------------------------\n");
        printf("\n");
        printf("\n");


        num++;
        sleep(1);

    }  
  
    close(route_sock);  
    close(forward_sock);  
  
    return 0;  
}