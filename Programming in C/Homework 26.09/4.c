//
//Напишете функцията за сумиране елементите на масив,
//използвайки адресна аритметика вместо инкрементиращa променливa


#include<stdio.h>

int main(){
int arr[100];
int numb;
int sum=0;
int j=1;

puts("number of elements ");
scanf("%d",&numb);

int *ptr=arr;
for(int i=0;i<numb;i++,j++)
{
        *ptr=j;
        sum=sum+*ptr;
        ptr++;
}

printf(" sum is : %d ",sum);


return 0;
}
