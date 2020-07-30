/*
1. Write a C program to swap the content of 2 variables using pointer. (use function)
*/

#include<stdio.h>

void swap(int * a,int * b){
    int k;
    k=*a;
    *a=*b;
    *b=k;
}

int main(){
    int p=1;
    int q=3;
    printf("Before Swapping:\n");
    printf("p: %d \t q:%d",p,q);
    swap(&p,&q);
    printf("\nAfter Swapping:\n");
    printf("p: %d \t q:%d",p,q);
    return 0;
}