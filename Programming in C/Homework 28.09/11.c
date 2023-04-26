//Напишете програма, която сортира масив, въведен от клавиатурата,
//използвайки указатели.


#include <stdio.h>

int main(){
int ar[]={6,1,4,2,3,5};
int *p=ar;
int leng=sizeof(ar)/sizeof(ar[0]);
int temp=0;

for(int i=0;i<leng;i++)
{
    for (int j=i+1;j<leng;j++)
    {

        if(*(p+i)<*(p+j))
        {
            temp=*(p+i);
            *(p+i)=*(p+j);
            *(p+j)=temp;
        }
    }
}

    for(int i=0;i<leng;i++)
    {
    printf("%d ",ar[i]);
    }



return 0;
}
