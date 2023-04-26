//Напишете програма, която сумира всички елементи на масив
//намиращи се на нечетна позиция. Масива да бъде въведен от потребителя.
//Разпечатайте в конзолата масива и сумата.
#include <stdio.h>


int main(){
int arr[100];
int numb;
int sum=0;
int *ptr=arr;

puts("number of elements ");
scanf("%d",&numb);


for(int i=0;i<numb;i++)
{
    scanf("%d",ptr);

    if(i%2!=0)
    {
        sum+=*ptr;
    }
    ptr++;
}

printf(" sum is : %d ",sum);
ptr=arr;

for(int i=0;i<numb;i++)
{
    printf(" %d \n",*ptr);
    ptr++;
}

return 0;
}
