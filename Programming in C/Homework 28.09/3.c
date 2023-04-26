//Напишете програма, която разменя елементите на два еднакви по размер
//масива, използвайки указатели.

#include <stdio.h>


int main(){

int ar[]={1,2,3,4,5};
int *p=ar;

int arr[]={11,22,33,44,55};
int *p1=arr;


for (int i=0;i<5;i++,p++,p1++)
{
int temp;
temp=*p1;
*p1=*p;
*p=temp;
printf(" %d ", ar[i]);

}


return 0;
}
