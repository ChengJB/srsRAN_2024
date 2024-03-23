#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <threads.h>

#define MAX_BUFFER 1024
#define PORT 62324
#define MAX_CLIENTS 2

int main()
{
    int listenSock, connSock[MAX_CLIENTS], ret, in, flags;
    struct sockaddr_in servaddr, clientaddr[MAX_CLIENTS];
    socklen_t clientLength;
    // set some property of sctp
    struct sctp_initmsg initmsg;
    struct sctp_event_subscribe events;
    struct sctp_sndrcvinfo sndrcvinfo;
    char buffer[MAX_BUFFER + 1];

    listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
    if (listenSock == -1)
    {
        printf("Failed to create socket\n");
        perror("socket()");
        exit(1);
    }

    bzero((void *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    ret = bind(listenSock, (struct sockaddr *)&servaddr, sizeof(servaddr));

    if (ret == -1)
    {
        printf("Bind failed \n");
        perror("bind()");
        close(listenSock);
        exit(1);
    }

    /* Specify that a maximum of 5 streams will be available per socket */
    memset(&initmsg, 0, sizeof(initmsg));
    initmsg.sinit_num_ostreams = 5;
    initmsg.sinit_max_instreams = 5;
    initmsg.sinit_max_attempts = 4;
    ret = setsockopt(listenSock, IPPROTO_SCTP, SCTP_INITMSG,
                     &initmsg, sizeof(initmsg));

    if (ret == -1)
    {
        printf("setsockopt() failed \n");
        perror("setsockopt()");
        close(listenSock);
        exit(1);
    }

    ret = listen(listenSock, 5);
    if (ret == -1)
    {
        printf("listen() failed \n");
        perror("listen()");
        close(listenSock);
        exit(1);
    }

    for (int i = 0; i < MAX_CLIENTS; i++)
    {

        printf("Awaiting connection for client %d\n", i);
        clientLength = sizeof(clientaddr[i]);
        connSock[i] = accept(listenSock, (struct sockaddr *)&clientaddr[i], &clientLength);
        if (connSock[i] == -1)
        {
            printf("accept() failed\n");
            perror("accept()");
            close(connSock[i]);
            continue;
        }
        else
        {
            printf("Client %d connected port => %d\n", i, ntohs(clientaddr[i].sin_port));
        }
    }

    while (1)
    {
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            in = sctp_recvmsg(connSock[i], buffer, sizeof(buffer),
                              (struct sockaddr *)NULL, 0, &sndrcvinfo, &flags);

            if (in == -1)
            {
                printf("Error in sctp_recvmsg\n");
                perror("sctp_recvmsg()");
                close(connSock[i]);
                continue;
            }
            else
            {
                buffer[in] = '\0'; // 添加 '\0' 终止字符串

                printf("Data received from client %d: %s\n", i, buffer);

                // 转发消息给另一个客户端
                int dest = (i + 1) % MAX_CLIENTS;
                ret = sctp_sendmsg(connSock[dest], buffer, strlen(buffer),
                                   NULL, 0, 0, 0, 0, 0, 0);
                if (ret == -1)
                {
                    printf("Error in sctp_sendmsg\n");
                    perror("sctp_sendmsg()");
                }
                else
                {
                    printf("send data to another client \n");
                }
            }
        }
    }

    // close all socket
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        close(connSock[i]);
    }
    close(listenSock);

    return 0;
}