/*
Write a client-server UDP socket program. This program is used to store and
query the student information, which will do following task.

    ● Client initiate the connection with server. Server will reply a Welcome 
      message and ask to enter any one of these commands OPTION or EXIT.
    ● When client will send OPTION command, the server will display following options.

    i. Add
    ii. View_roll number/ view_all
    iii. Delete_roll number/ Delete_all
    iv. Roll-number_avg / Class_avg

Functionality of these commands should be-

    Add :- This command allow client to add the new student information at server.
    A student information will consist of-
    - Roll number
    - Class
    - Subject_1 marks (out of 100)
    - Subject_2 marks
    - Subject_3 marks
    The server should use structure to store this information.

    View_roll number / View_all :- This command allows a client to view the
    information of a student individually via View_roll number or for the whole
    class via View_all command.

    Delete_roll number / Delete_all :- This command allows a client to delete
    the information of individual student or for whole class.

    Roll-number_avg / Class_avg :- This command will allow a client to get the
    average of subject_1, subject_2 and subject_3 of an individual student via
    Roll-number_avg command or the average of whole class via Class_avg
    command.

    Exit :- This command will terminate the session after displaying goodbye
    message.

    After each execution of a command (except Exit) the control should come
    back to Option or Exit page so that a client can run commands multiple
    times until he/she selects exit command.
*/


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