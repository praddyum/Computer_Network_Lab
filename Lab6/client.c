
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <string.h>

struct stud{
    char op;
    int op1,op2;
};

int main(){
    
    struct stud stu_cli,stu_send;

    printf("Input[Ex format: 21 + 34]:\n ");
   
    scanf("%d",&(stu_cli.op1));
    scanf("%s ",&(stu_cli.op));
    scanf(" %d",&(stu_cli.op2));
    
    printf("%d",stu_cli.op2);

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
 
    //Part 5: Sending message
    if(send(sock_fd,&stu_cli,sizeof(struct stud),0)<0){
        puts("Send Failed\n");
        return -1;
    }
    puts("\nData Sent to server for Computation...");

    //Part 6: Receive Message
    if(recv(sock_fd,&stu_send,sizeof(struct stud),0)<0){
        puts("receive failed");
        return -1;
    }
    printf("\nSol: %d",stu_send.op1);

    return 0;
}