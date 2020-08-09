/*Write a c program using command line argument to
 add two numbers.
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    float a,b,i;
    if( argc == 3 )
    {
        a=atof(argv[1]);
        b=atof(argv[2]);
        i=(float)a+(float)b;
        printf("%.2f",i);
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