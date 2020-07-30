/*
2. Write a C program to assign values to each members of the following structure. Pass the populated structure to a function Using call-by address and 
print the value of each member of the structure with in that function. struct info{ int roll_no; char name[50]; float CGPA; }
*/

#include<stdio.h>

struct info{
    int roll_no;
    char name[50];
    float CGPA;
};

void printing(struct info * obj){
    printf("\nRoll: %d",obj->roll_no); 
    printf("\nName: %s",obj->name); 
    printf("\nCGPA: %f",obj->CGPA); 
}

int main(){

    struct info obj1;
    printf("Roll:" );
    scanf("%d",&obj1.roll_no); 
    printf("Name:" );
    scanf("%s",obj1.name); 
    printf("CGPA:" );
    scanf("%f",&obj1.CGPA); 
    printing(&obj1);
    return 0;
}