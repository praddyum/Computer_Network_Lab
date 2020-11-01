/*2. WAP in c to bind the socket with IP address, port number given through command line argument and display message accordingly. [connection less communication.]
*/

#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
int main(int argc,char *argv[]){
    int sockfd;
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
     
    if(sockfd == -1){
        printf("Client Socket not Created\n");
        exit(0);
    }
    else{
         printf("Client socket created successfully\n");
    }


    struct sockaddr_in myaddr;
    myaddr.sin_family=AF_INET;
    myaddr.sin_port=htons(atoi(argv[1]));
    myaddr.sin_addr.s_addr=inet_addr(argv[2]);
    
    //Binding
    if(bind(sockfd,(struct sockaddr *)&myaddr,sizeof(myaddr))<0){
    	puts("Server Bind failed");
        exit(1);
    }
	
    puts("Server Bind Successful\n");

    return 0;
}

