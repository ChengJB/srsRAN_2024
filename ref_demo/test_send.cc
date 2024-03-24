#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  



#define SEND_PORT 1111  
#define SEND_IP "10.24.145.5"

#define END_PORT 2222
#define END_IP "10.24.145.5"

int main(){
            // create socket
            int send_sock=socket(AF_INET, SOCK_DGRAM, 0);
            // bind  address
            struct sockaddr_in send_addr;   
            memset(&send_addr, 0,sizeof(send_addr));
            send_addr.sin_family = AF_INET;
            send_addr.sin_addr.s_addr = inet_addr(SEND_IP);
            send_addr.sin_port = htons(SEND_PORT);
            bind(send_sock, (struct sockaddr*)&send_addr, sizeof(send_addr));
            //send data
            struct sockaddr_in end_addr;   
            memset(&end_addr, 0,sizeof(end_addr));
            end_addr.sin_family = AF_INET;  
            end_addr.sin_addr.s_addr = inet_addr(END_IP);  
            end_addr.sin_port = htons(END_PORT);  
            int num=0;
            //send data
            while(1){
            char send_data[] = "1234567890";
            ssize_t send_id=sendto(send_sock, send_data, strlen(send_data), 0, (struct sockaddr*)&end_addr, sizeof(end_addr));
            printf("---------------sending----------------\n");
            printf("index: %d\n",num);
            printf("my ip:               %s:%d\n",inet_ntoa(send_addr.sin_addr), ntohs(send_addr.sin_port));
            printf("target ip :          %s:%d\n",inet_ntoa(end_addr.sin_addr), ntohs(end_addr.sin_port));
            printf("send bytes length :  %zd\n",send_id);
            printf("send data is         %s\n",send_data);
            printf("-----------------------------------------\n");
            printf("\n");
            printf("\n");
            num++;
            sleep(1);
            }
           
            close(send_sock);
            
        

        

    return 0;
}