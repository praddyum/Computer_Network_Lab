/*
5. Write a C program to check whether the Host machine is in Little Endian or Big Endian. Enter a number, print the content of each byte
location and Convert the Endianness of the same i.e. Little to Big Endian and vice-versa.

Resources : https://www.geeksforgeeks.org/little-and-big-endian-mystery/ 
            https://stackoverflow.com/questions/31138835/what-is-the-meaning-of-ii-chari-and-a-chara-in-the-following-code
            https://www.quora.com/What-does-2x-do-in-C-code

*/

#include<stdio.h>

void printing(unsigned char *val,int n){
    int k;
    for(k=0;k<n;k++){
        printf("%.2x  ",val[k]);
    }
    if(val[0]=44){
        printf("\nLittle Endian");
    }
    else
        printf("\nBig Endian");
    
    printf("\n");
    printf("\nLittle Endian\n");
    for(k=0;k<n;k++){
        printf("%.2x  ",val[k]);
    }
    printf("\nBig Endian\n");
    for(k=n-1;k>-1;k--){
        printf("%.2x  ",val[k]);
    }
}

int main()
{
    int i=12578329;
    printing((unsigned char*)&i,sizeof(i));  
    return(0);
} 