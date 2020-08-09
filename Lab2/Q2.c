/*Write a c program using command line argument to calculate average of 5 numbers.*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    float i=0;
    if( argc == 6 )
    {
        for(int k=1;k<6;k++){
            i+=atof(argv[k]);
        }
        i=i/5;
        printf("%.2f",i);
    }
    else
    {
        printf("argument list is empty. Or either incomplete\n");
    }
    return 0;
}