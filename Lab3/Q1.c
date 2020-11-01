//1. WAP in c to create a socket and display the message accordingly.[connection less communication.]

#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    int sockfd;
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
     
    if(sockfd == -1){
        printf("Socket not Created\n");
        exit(0);
    }
    else{
         printf("Socket created successfully\n");
    }
    return 0;
}