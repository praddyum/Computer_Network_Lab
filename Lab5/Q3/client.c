/*
client file
Wap in TCP server already stored the array of 5 
students roll, name & mark. Client only send the roll no 
to client. Then server will return name and cgpa to that 
student.

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <string.h>


int main(){

    int sock_fd,val;                                          //Socket ID  | val to send
    struct sockaddr_in server;                            //server to hold the information of server

    char server_reply[30];                                //receive message buffers
    float cgpa;

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

    //Part 4: Crafting the message to send
    printf("Roll: ");
    scanf("%d",&val);

    
    //Part 5: Sending message
    if(send(sock_fd,&val,4,0)<0){
        puts("Send Failed\n");
        return -1;
    }
    puts("Data Sent");

    //Part 6: Receive name from server
    if(recv(sock_fd,server_reply,30,0)<0){
        puts("receive failed");
        return -1;
    }
    printf("Data Fetched: ");
    printf("\nName: ");
    puts(server_reply);
    
    //Part 7: Receive CGPA from server
    if(recv(sock_fd,&cgpa,sizeof(float),0)<0){
        puts("receive failed");
        return -1;
    }
    printf("CGPA: ");
    printf("%0.2f",cgpa);

    return 0;
}