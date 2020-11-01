/*3. WAP in c to send a message from client to server and server will print the same message.[connection less communication.]
*/

//UDP SERVER
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
int sockfd,length;
char buf[100];

sockfd=socket(AF_INET,SOCK_DGRAM,0);


struct sockaddr_in sa,ca;
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=60018;
bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));

length=sizeof(ca);

recvfrom(sockfd,buf,100,0,(struct sockaddr *)&ca,&length);

printf("Received: %s  ",buf);

close(sockfd);
}
