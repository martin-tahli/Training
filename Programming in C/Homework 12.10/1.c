//Да се направи програма, която заделя динамичен масив с брой
//елементи зададени от потребителя. За всеки елемент от масива се очаква
//потребителят да въведе цяло и число и след това се изчислява сумата на
//всички елементи от масива



#include <stdio.h>
#include <stdlib.h>


int main(){

puts("enter amount of ints");
int num;
scanf("%d",&num);
int elem;
int sum=0;
int *ptr=(int*) malloc(num*sizeof(int));

for (int i=0;i<num;i++)
{
    scanf("%d",&elem);
    ptr[i]=elem;
    sum+=elem;
}
printf("%d",sum);
free(ptr);
return 0;
}
