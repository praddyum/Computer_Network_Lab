/*
3. Write a C program to extract each byte from a given number and store them in separate character variables and print the content of those variables. 
*/

#include<stdio.h>

int main(){
    int a=12578329;
    unsigned char * n=(unsigned char*)&a;
    for(int i=0;i<sizeof(a);i++)
    {
        printf("%.2x",n[i]);
        printf("\t");
    }
    return 0;
}

