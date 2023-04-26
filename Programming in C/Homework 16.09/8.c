/*. Напишете програма, която да отделя в два отделни масива
четните и нечетните числа от даден масив с цели числа. Масива
да бъде въведен от клавиатурата. Принтирайте оригиналния и
двата резултатни масива.*/


#include <stdio.h>




int main(){

int arr[10];
int even[10];
int odd[10];
int i;
printf("Enter the numbers");

for(i=0;i<10;i++)
{
    scanf("%d",&arr[i]);
    if(arr[i]%2==0)even[i]=arr[i];
    else odd[i]=arr[i];

}
printf("\n Original  numbers are: ");
for(i=0;i<10;i++)
{
printf(" %d ",arr[i]);
}

printf("\n Odd numbers are: ");
for(i=0;i<10;i++)
{
printf(" %d ",odd[i]);
}

printf("\n Even numbers are: ");
for(i=0;i<10;i++)
{
printf(" %d ",even[i]);
}

return 0;
}
