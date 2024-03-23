#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <pthread.h>

#define MAX_BUFFER 1024
#define PORT 6000
#define MAX_CLIENTS 2

struct ThreadArgs
{
    int *sockets;
    int index;
};

void listenSoket(void *arguments)
{
    struct ThreadArgs *args = (struct ThreadArgs *)arguments;
    int *connSock = args->sockets;
    int i = args->index;
    char buffer[MAX_BUFFER + 1];
    int in, ret;
    printf("listen for index: %d \n", i);
    while (1)
    {
        struct sockaddr_in enb_addr;
        socklen_t fromlen = sizeof(enb_addr);
        struct sctp_sndrcvinfo sri;
        int msg_flags = 0;
        in = sctp_recvmsg(connSock[i], buffer, sizeof(buffer),
                          (struct sockaddr *)&enb_addr, &fromlen, &sri, &msg_flags);
        printf("stream id %d",sri.sinfo_stream);

        if (in == -1)
        {
            printf("Error in sctp_recvmsg\n");
            perror("sctp_recvmsg()");
            close(connSock[i]);
            continue;
        }
        else if (in > 0)
        {
            printf("Data received from client %d: %s\n", i, buffer);
            // 转发消息给另一个客户端
            int dest = (i + 1) % MAX_CLIENTS;
            ret = sctp_sendmsg(connSock[dest], buffer, sizeof(buffer),
                               NULL, 0,
                               htonl(18),
                               0,
                               0,
                               0,
                               0);
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

int main()
{
    int listenSock, connSock[MAX_CLIENTS], ret, in, flags;
    struct sockaddr_in servaddr, clientaddr[MAX_CLIENTS];
    socklen_t clientLength;
    // set some property of sctp
    struct sctp_initmsg initmsg;
    struct sctp_event_subscribe events;
    struct sctp_sndrcvinfo sndrcvinfo;

    // connect to epc server
    connSock[0] = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
    if (connSock[0] == -1)
    {
        printf("Socket creation failed\n");
        perror("socket()");
        exit(1);
    }
    bzero((void *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(36412);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = connect(connSock[0], (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1)
    {
        printf("Connection failed\n");
        perror("connect()");
        close(connSock[0]);
        exit(1);
    }
    printf("center connect to epc server success \n");

    // listen part --- 6000
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

    for (int i = 1; i < MAX_CLIENTS; i++)
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

    // process data
    pthread_t threads[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        struct ThreadArgs *args = malloc(sizeof(struct ThreadArgs));
        args->sockets = connSock;
        args->index = i;
        int error = pthread_create(&threads[i], NULL, listenSoket, (void *)args);

        if (error != 0)
        {
            printf("Failed to create thread %d: %s\n", i, strerror(error));
            return 1;
        }
    }
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // close all socket
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        close(connSock[i]);
    }
    close(listenSock);

    return 0;
}
