/*
Client file
Wap in TCP client will send the structure student to 
server having data member roll, mark1 and mark2. And 
server will return the same structure by swapping their 
mark to client
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <string.h>

struct stud{
    int roll;
    float mark1,mark2;
};

int main(){

    struct stud stu_cli,stu_send;

    stu_cli.roll=1;
    stu_cli.mark1=20.5;
    stu_cli.mark2=13.1;

    int sock_fd;                                          //Socket ID  | val to send
    struct sockaddr_in server;                            //server to hold the information of server


    //part 1: Initializing a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);            //Creating Socket
    if(sock_fd==-1){
        puts("Client Socket Creation Failed!!");
        exit(1);
    }

    //Part 2: Configuring server details
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    server.sin_port = htons(9999);
    server.sin_family=AF_INET;

    //Part 3: Connect to server
    if(connect(sock_fd,(struct sockaddr *)&server, sizeof(server))<0){
        puts("Connection failed");
        exit(1);
    }
    puts("Connected with server\n");
    
    printf("\nMarks before swapping for Roll= %d : \n",stu_cli.roll);
    printf("Mark 1: %0.2f",stu_cli.mark1);
    printf("\nMark 2: %0.2f",stu_cli.mark2);

    //Part 5: Sending message
    if(send(sock_fd,&stu_cli,sizeof(struct stud),0)<0){
        puts("Send Failed\n");
        return -1;
    }
    puts("\nData Sent to server for swapping...");

    //Part 6: Receive Message
    if(recv(sock_fd,&stu_send,sizeof(struct stud),0)<0){
        puts("receive failed");
        return -1;
    }
    printf("\nReceived Swapped Marks for Roll= %d : \n",stu_cli.roll);
    printf("Mark 1: %0.2f",stu_send.mark1);
    printf("\nMark 2: %0.2f",stu_send.mark2);

    return 0;
}