#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  

#define recv_port 8888
#define recv_ip "127.0.100.5"


int main()  
{
    //创建套接字
    int rec_sock=socket(AF_INET,SOCK_DGRAM,0);
    //定义服务器地址
    struct sockaddr_in rec_addr;
    memset(&rec_addr,0,sizeof(rec_addr));
    rec_addr.sin_family=AF_INET;
    rec_addr.sin_addr.s_addr=inet_addr(recv_ip);
    rec_addr.sin_port=htons(recv_port);
    //绑定套接字
    bind(rec_sock,(struct sockaddr*)&rec_addr,sizeof(rec_addr));
    int num=0;

    while (1)
    {
       
        
        struct sockaddr_in from_addr;
        socklen_t len=sizeof(from_addr);  
        char buffer[1500]="";
        ssize_t rec_id=recvfrom(rec_sock,buffer,sizeof(buffer),0,(struct sockaddr*)&from_addr,&len);   
        
        
        
        printf("---------------receiving----------------\n");
        printf("index: %d\n",num);
        printf("my ip:\t\t%s:%d\n",inet_ntoa(rec_addr.sin_addr), ntohs(rec_addr.sin_port));
        printf("source ip :\t%s:%d\n",inet_ntoa(from_addr.sin_addr), ntohs(from_addr.sin_port));
        printf("receive bytes length :\t%zd\n",rec_id);
        printf("receive data is\t%s\n",buffer);
        printf("------------------------------------------\n");
        printf("\n");
        printf("\n");
       
        num++;
    }
    
    
    //关闭套接字
    close(rec_sock);    
    
    return 0;
}