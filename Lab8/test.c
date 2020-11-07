#include<stdio.h>
#include<stdlib.h>

struct stufs
{
    int roll;
};

int main(){

    struct stufs * optr;
    struct stufs * nptr;
    int size=0,sn,i,val;

    //Adding values
    while(1){
        printf("Size :");
        scanf("%d",&sn);
        
        //Memory Allocation
        if(size==0){
            optr=(struct stufs *)malloc(sn*sizeof(struct stufs));
        }
        else{
            nptr=(struct stufs *)malloc((sn+size)*sizeof(struct stufs));
        }

        //Copying Old data
        if(size!=0){
            for(i=0;i<size;i++){
                (nptr[i]).roll=(optr[i]).roll;
            }
        }

        //Input new Data
        for(i=size;i<(size+sn);i++){
            scanf("%d",&(nptr[i]).roll);
          
        }

        //Output
        for(i=0;i<size+sn;i++){
            printf("%d ",nptr[i].roll);
        }

        //Update value of size
        size=size+sn;

        //Updating pointers
        optr=nptr;

        //Exit Ques
        printf("\nWanna go out? 1/0");
        scanf("%d",&val);
        if(val==1){
            break;
        }
    }
    return 0;
}