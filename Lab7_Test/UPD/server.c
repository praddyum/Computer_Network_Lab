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
int conson=0;
sockfd=socket(AF_INET,SOCK_DGRAM,0);

struct sockaddr_in sa,ca;
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=60018;
bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));

length=sizeof(ca);

recvfrom(sockfd,buf,100,0,(struct sockaddr *)&ca,&length);

printf("Received: %s",buf);

for(int i=0;i<100;i++){
    
    if((buf[i]>=65 && buf[i]<=90)|| (buf[i]>=97 && buf[i]<=122))
    	{
            if(buf[i]=='a'|| buf[i]=='e'||buf[i]=='i'||buf[i]=='o'||buf[i]=='u'||buf[i]=='A'||buf[i]=='E'||buf[i]=='I'||buf[i]=='O' ||buf[i]=='U'){
                //it will be vowel
            }
            else if ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z')) {
            ++conson;
            }
}
}
printf("\n\nTotal Consonants: %d",conson);
close(sockfd);

return 0;

}