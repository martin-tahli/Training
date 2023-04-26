//Напишете програма, която проверява дали две дадени матрици са
//еднакви, сравнявайки съответните елементи в тях. Разпечатайте в конзолата
//двете изходни матрици и резултата от сравнението.

#include <stdio.h>
#define size 2

int main(){
int arr[size][size]={};
int arr2[size][size]={};
puts("enter first matrix");
for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    {
        scanf("%d",&arr[i][j]);
    }
}
puts("enter second matrix");

for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    {
        scanf("%d",&arr2[i][j]);
    }
}
for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    {
        printf("%d ",arr[i][j]);
    }
    printf ("\n");
}
for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    {
        printf("%d ",arr2[i][j]);
    }
    printf ("\n");
}
int flag=0;
for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    {
        if(arr2[i][j]==arr[i][j]){flag=1;}
        else flag=0;break;
    }
    printf ("\n");
}
if(flag==1){puts("identic");}
else puts("not identic");


return 0;
}
