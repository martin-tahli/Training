/*Напишете програма, която да завърти даден масив от цели
числа с N позиции наляво. Масива и числото N трябва да бъдат
въведени от клавиатурата. Принтирайте оригиналния и
резултатния масиви. Пример:*/

#include <stdio.h>


int main(){
printf ("enter size of array ");
int size;
scanf("%d",&size);
int n,i;
printf ("enter  N ");
scanf("%d",&n);

int arr[size];
int tempArr[size];

int d=0;


for(i=0;i<size;i++)
{
    scanf("%d", &arr[i]);
}
printf("\nOriginal array\n");
for(i=0;i<size;i++)
{
    printf(" %d ", arr[i]);
}
printf("\nSecondary array\n");
for(i=0;i<size;i++)
{

    tempArr[i]=arr[i+n];
    if (i+1>size-n)
    {
        tempArr[i]=arr[d];
        d++;
    }


printf(" %d ",tempArr[i]);
}



return 0;
}
