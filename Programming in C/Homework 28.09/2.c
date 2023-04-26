
//Напишете програма, която копира един масив в друг, използвайки
//указатели.

#include <stdio.h>


int main(){

int ar[]={1,2,3,4,5};
int *p=ar;

int arr[5];
int *p1=arr;


for (int i=0;i<5;i++,p++,p1++)
{
*p1=*p;
printf(" %d ", arr[i]);

}


return 0;
}
