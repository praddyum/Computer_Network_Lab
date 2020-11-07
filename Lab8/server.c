/*
Write a client-server UDP socket program. This program is used to store and
query the student information, which will do following task.

    ● Client initiate the connection with server. Server will reply a Welcome 
      message and ask to enter any one of these commands OPTION or EXIT.
    ● When client will send OPTION command, the server will display followingoptions.

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
       
//    struct stud stu_ser,stu_send; 
    int sock_fd,new_sock,c;                                          //Socket ID
    struct sockaddr_in server,client;                            //server to hold the information of server
    char choice1[30],choice2[50];
    char greet[50]="Welcome \"\n\" Choose one 1.OPTION 2.EXIT";
    char list[100]="Choose 1 \"\n\" 1: Tata \"\n\"2: Bata";

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

    while(1){

        //Sending greet message
        if(send(new_sock,&greet,sizeof(greet),0)<0){
        puts("Send Failed\n");
        return -1;
        }
        puts("Sent Greet....");    

        //receive ch1
        if(recv(new_sock,&choice1,sizeof(choice1),0)<0){
        puts("receive failed");
            return -1;
        }
        puts(choice1);
        if(strcmp(choice1,"EXIT")==0){
            exit(0);
        }

        //if ch1==OPTIONS
        else {
            //Sending list message
            if(send(new_sock,&list,sizeof(list),0)<0){
            puts("Send Failed\n");
            return -1;
            }
            puts("Sent List....");    
        }
            
    }

    return 0;
}