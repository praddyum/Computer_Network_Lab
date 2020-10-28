//UDP CLIENT
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
int i,sockfd;
char buf[100];
sockfd=socket(AF_INET,SOCK_DGRAM,0);

//------------------------------server info------------------------------------
struct sockaddr_in sa;
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");//loop back ip address
sa.sin_port=60018;
//------------------------------------------------------------------------


printf("Enter a message\t");
scanf("%[^\n]s",buf);
//------sending message to server--------------------------
sendto(sockfd,buf,strlen(buf),0,(struct sockaddr *)&sa,sizeof(sa));//send to server so used "(struct sockaddr *)&sa" 
close (sockfd);
}