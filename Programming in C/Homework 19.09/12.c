/*Напишете програма, която принтира съдържанието на масив, като показва позицията в масива
на горния ред*/

#include <stdio.h>

int main(){
int arr[]={10,3,4,6,62,3,8,465,21};
int lenght=sizeof(arr)/sizeof(arr[0]);
int *p=arr;


for(int i =0;i<lenght;i++)
{
printf(" %d ",i);
}
printf(" \n ");

for(int j=0;j<lenght;j++)
{
printf("%d  ",*p);p++;
}
return 0;
}
