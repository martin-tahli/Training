

/* Напишете програма, която събира две матрици (4х4) и записва резултата в трета такава със същия размер.
Събирането на матриците става като намерим сумата на съответстващите елементи в тях. Данните за изходните
матрици трябва да бъдат въведени от потребителя. Разпечатайте трите матрици в конзолата.
*/

#include <stdio.h>


int main(){

int arr[2][2]={1,2,3,4};
int arr2[2][2]={1,2,3,4};
int res[2][2];
int i,j;


for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        res[i][j]=arr[i][j]+arr2[i][j];
    }
}
printf("\n the first matrix\n");
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        printf(" %d ",arr[i][j]);
    }
    puts("");
}
printf("\n the second matrix\n");
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        printf(" %d ",arr2[i][j]);
    }
    puts("");
}

printf("\n the result matrix\n");
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        printf(" %d ",res[i][j]);
    }
    puts("");
}





return 0;}
