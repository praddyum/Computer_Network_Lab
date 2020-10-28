//client file
/*Client sends one integer. Server reverse the number and send back 
to client.*/
#include <stdio.h>
#include <sys/socket.h>     
#include <arpa/inet.h>      
#include <string.h>         
#include <stdlib.h>

int main(int argc,char *argv[]){
    int sock_fd,n;
    struct sockaddr_in server;
    
    sock_fd=socket(AF_INET,SOCK_STREAM,0);                
    if(sock_fd == -1) {
        puts("Client socket creation FAILED\n");
        exit(1);
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");             
    server.sin_port = htons(6666);                      
    server.sin_family= AF_INET;

    if(connect(sock_fd, (struct sockaddr *) &server, sizeof(server))<0){
        puts("Connection failed");
        exit(1);
    }
    puts("Connection with server Successfull\n");
    printf("Input an ineger: ");
    scanf("%d",&n); 
    send(sock_fd,&n,sizeof(int),0);
    recv(sock_fd,&n,sizeof(int),0);
    printf("Server: %d\n",n);
    
    return 0;
    
}