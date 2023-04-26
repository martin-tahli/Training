/*Напишете програма, която въвежда масив от цели числа от клавиатурата. Сортирайте го във
възходящ ред. След това от клавиатурата въведете цяло число и го поставете на правилната
му позиция в масива, така че да не се нарушава реда. Принтирайте масива.*/

#include <stdio.h>
int n=10;
void sort(int arr[])
{
    for(int i=0;i<n;i++)
    {
    int temp;
        for(int j=0;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(){
int Enew;

printf("input elements of the arr ");

int arr[n];
for(int i=0;i<n-1;i++)
{
    scanf("%d",&arr[i]);
}
sort(arr);

for(int i=1;i<n;i++)
{
    printf(" %d ",arr[i]);
}
printf("input the new element  of the arr ");
scanf("%d",&Enew);

arr[0]=Enew;
sort(arr);
for(int i;i<n;i++)
{
    printf(" %d ",arr[i]);
}


return 0;
}
