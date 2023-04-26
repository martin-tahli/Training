/*Напишете програма, която да намери максималния и
минималния елемент в масив от цели числа. Масива трябва да
бъде въведен от клавиатурата. Принтирайте целия масив и
резултатите.*/

#include <stdio.h>


int main(){
int arr[10];
int max,min;
int i;
int lenght;
lenght=sizeof(arr)/sizeof(arr[0]);



for (i=0;i<lenght;i++)
{   scanf("%d",&arr[i]);
}
max=arr[0];
min=arr[0];
for (i=0;i<lenght;i++)
{
        if (max<arr[i])
        {
        max=arr[i];
        }

        if(min>arr[i])
        {
        min=arr[i];
        }
 printf(" %d ",arr[i] );
}
printf("\n min-> %d  max-> %d\n",min, max);




return 0;
}
