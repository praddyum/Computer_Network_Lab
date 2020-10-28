/*Write a C program to display the IP 
address and port number using command line argument.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int port;
    char ip[30];
    if( argc == 3 )
    {
        port=atoi(argv[1]);
        strcpy(ip,argv[2]);
        printf("Port: %d\n",port);
        printf("IP: %f",ip);
        
    }
    else if( argc==2 ){
        printf("Input two numbers only.\n \"Error in Input\"");
    }
    else
    {
        printf("argument list is empty.\n");
    }
    return 0;
}