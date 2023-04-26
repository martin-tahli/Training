//Напишете програма, която намира максималния и минималния елементи
////в масив, използвай указатели.

#include <stdio.h>


int main(){
int ar[]={5,46,2,3,1,5};
int leng=sizeof(ar)/sizeof(ar[0]);
int min=ar[0];
int max=ar[0];
int *pmin=&min;
int *pmax=&max;

for(int i=0;i<leng;i++)
{
   if(ar[i]<*pmin){*pmin=ar[i];}
   if(ar[i]>*pmax){*pmax=ar[i];}

}
printf(" %d   %d",*pmin,*pmax);


return 0;}
