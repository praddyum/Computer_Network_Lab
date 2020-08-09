/*
Write a C program to assign values to each members of the following structure using 
command line arguments. 
Pass the populated structure to a function Using call-by address and print the value 
of each member of 
the structure with in that function. 
struct info {
 int roll_no; 
 char name[50];
 float CGPA; 
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {

    int roll_no;
    char name[50];
    float CGPA;
};

void printing(struct info * ptr){

    printf("Roll: %d\n",ptr->roll_no);
    printf("Name: %s\n",ptr->name);
    printf("CGPA: %.2f\n",ptr->CGPA);

}


int main(int argc, char *argv[]){

    struct info ob1;
    if( argc == 4 )
    {
        ob1.roll_no=atoi(argv[1]);
        strcpy(ob1.name,argv[2]);
        ob1.CGPA=atof(argv[3]);
        printing(&ob1);
    }

    else
    {
        printf("argument list is empty. or not complete. Make sure to input Roll, name, CGPA in same sequence\n");
    }
    return 0;
}


