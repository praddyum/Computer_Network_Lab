/*
4. Write a C Program to enter a number and store the number across the following structure and print the content of each member of the structure. 
Then aggregate each member of the structure to form the original number and print the same.
struct pkt{
char ch1;
char ch2[2];
char ch3;
};

*/

#include<stdio.h>

struct pkt{
    unsigned char ch1;
    unsigned char ch2[2];
    unsigned char ch3;
};

int main(){
    
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    
    unsigned char * s=(unsigned char *)&num;
    
    struct pkt ob1;
    
    ob1.ch1=s[0];
    ob1.ch2[0]=s[1];
    ob1.ch2[1]=s[2];
    ob1.ch3=s[3];

    printf("char1= %.2x",ob1.ch1);
    printf("\nchar2[0]= %.2x",ob1.ch2[0]);
    printf("\nchar2[1]= %.2x",ob1.ch2[1]);
    printf("\nchar3= %.2x",ob1.ch3);

    int val=((int)(ob1.ch3<<24)+(int)(ob1.ch2[1]<<16)+(int)(ob1.ch2[0]<<8)+(int)(ob1.ch1));
    printf("\n%d",val);
    return 0;
}