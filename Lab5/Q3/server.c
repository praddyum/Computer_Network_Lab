/*
server file
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

struct stud{
    int roll;
    char name[30];
    float cgpa;
};

int main(){
    
    //structure initialization
    struct stud stu[5];
    stu[0].roll=1;
    strcpy(stu[0].name,"Rakesh");
    stu[0].cgpa=9.4;

    stu[1].roll=2;
    strcpy(stu[1].name,"Parmeet");
    stu[1].cgpa=9.9;

    stu[2].roll=3;
    strcpy(stu[2].name,"Amrit");
    stu[2].cgpa=8.4;

    stu[3].roll=4;
    strcpy(stu[3].name,"Joseph");
    stu[3].cgpa=9.2;

    stu[4].roll=5;
    strcpy(stu[4].name,"Rinky");
    stu[4].cgpa=10;

    
    int sock_fd,new_sock,c,receved_val,flag=0;                                          //Socket ID
    struct sockaddr_in server,client;                            //server to hold the information of server

    char name_send[30];                    //Send receive message buffers
    float cgpa_send;
    
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

    //Part 4: receive message
    if(recv(new_sock,&receved_val,4,0)<0){
        puts("receive failed");
        return -1;
    }
    puts("Received query : \n");
    printf("%d",receved_val);

    //Part 5: Check for val in struct

    for(int i=0;i<5;i++){
        if(stu[i].roll==receved_val){
            strcpy(name_send,stu[i].name);
            cgpa_send=stu[i].cgpa;
            flag=1;
        }
    }

    //Part 6: Send the name and CGPA
    if(flag==1){
        //Send name
        if(send(new_sock,name_send,30,0)<0){
        puts("Send Failed\n");
        return -1;
    }
    puts("Name Sent");

        //Send CGPA
        if(send(new_sock,&cgpa_send,sizeof(float),0)<0){
        puts("Send Failed\n");
        return -1;
        }
    puts("CGPA Sent");    
    }

    //Part 6: Send not found
    else{
        //Send name
        strcpy(name_send,"Not found");
        if(send(new_sock,name_send,30,0)<0){
        puts("Send Failed\n");
        return -1;
    }
    puts("Name Sent");

        //Send CGPA
        cgpa_send=0;
        if(send(new_sock,&cgpa_send,sizeof(float),0)<0){
        puts("Send Failed\n");
        return -1;
        }
    puts("CGPA Sent");    
    }

    return 0;
}