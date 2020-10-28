
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <string.h>

struct stud{
    int roll;
    int class;
    float su1,su2,su3;
};

int main(){

    int sock_fd;                                          //Socket ID  | val to send
    struct sockaddr_in server;                            //server to hold the information of server
    char choice1[30],list[100],choice2[50];
    char greet[50];

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
    
    while(1){
        
        //To recive greet
        if(recv(sock_fd,&greet,sizeof(greet),0)<0){
        puts("receive failed");
        return -1;
        }

        puts(greet);

        //Userget ch1
        fgets(choice1,50,stdin);

        //Send ch1
        if(send(sock_fd,&choice1,sizeof(choice1),0)<0){
        puts("Send Failed\n");
        return -1;
        }
        puts("\nChoice 1 Sent");    

        //if ch1==exit
        if(strcmp(choice1,"EXIT")==0){
            break;
        }

        //Recv the list
        if(recv(sock_fd,&list,sizeof(list),0)<0){
        puts("receive failed");
        return -1;
        }

        //print list
        puts(list);

        //Deciding the ch2
        fgets(choice2,100,stdin);
        
        //condition 1 - ch2 == ADD
        if(strcmp(choice1,"ADD")==0){

        }

        //condition 2 - ch2 == View_roll number
        else if(strcmp(choice1,"View_roll number")==0){

        }

        //condition 3 - ch2 == View_all
        else if(strcmp(choice1,"View_all")==0){

        }

        //condition 4 - ch2 == Delete_roll number
        else if(strcmp(choice1,"Delete_roll number")==0){

        }

        //condition 5 - ch2 == Delete_all
        else if(strcmp(choice1,"Delete_all")==0){

        }

        //condition 6 - ch2 == Roll_number_avg
        else if(strcmp(choice1,"Roll_number_avg")==0){

        }

        //condition 7 - ch2 == Class_avg
        else if(strcmp(choice1,"Class_avg")==0){

        }


        //sending ch2
        if(send(sock_fd,&choice2,sizeof(choice2),0)<0){
        puts("Send Failed\n");
        return -1;
        }
        puts("\nChoice 2 Sent");    

        
    }

    return 0;
}