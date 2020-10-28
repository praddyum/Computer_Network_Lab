
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
        
    struct stud stu_ser,stu_send; 
    int sock_fd,new_sock,c;                                          //Socket ID
    struct sockaddr_in server,client;                            //server to hold the information of server

    
    //part 1: Initializing a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);            //Creating Socket
    if(sock_fd==-1){
        puts("Client Socket Creation Failed!!");
        exit(1);
    }

    //Part 2: Configuring server details
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port = htons(9999);
    server.sin_family=AF_INET;

    //Part 3: Bind Sock_fd with ip and port
    if(bind(sock_fd, (struct sockaddr *)&server, sizeof(server))<0){
        puts("Bind Failed\n");
        exit(1);
    }
    puts("Bind Successful\n");

    //Part 4: Configure listen to limit number of connection at any instance
    listen(sock_fd, 5);

    //Part 5: Wait for connection and assign the details to new_sock
    c=sizeof(struct sockaddr_in);
    new_sock = accept(sock_fd, (struct sockaddr *)&client, (socklen_t *)&c);

    if(new_sock < 0)
        puts("Accept Failed\n");
    puts("Connection Accepted");

    //Part 6: receive message
    if(recv(new_sock,&stu_ser,sizeof(struct stud),0)<0){
        puts("receive failed");
        return -1;
    }

    //Part 7: Perform Computation
    switch(stu_ser.op){
        case '+' : stu_ser.op1=stu_ser.op1+stu_ser.op2;
                   break;

        case '-' : stu_ser.op1=stu_ser.op1-stu_ser.op2;
                   break;
        case '*' : stu_ser.op1=stu_ser.op1*stu_ser.op2;                 
        
    }

    //Part 8: Sending back struct
    if(send(new_sock,&stu_ser,sizeof(struct stud),0)<0){
        puts("Send Failed\n");
        return -1;
    }
    puts("Sent ....");

    return 0;
}