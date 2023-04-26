//Напишете примерна програма, която връща няколко стойности от
//функция, използвайки указател.

#include <stdio.h>

int sum (int a,int b,int sum)
{
int *aa=&a;
int *bb=&b;
int *ssum=&sum;

    *ssum=*aa+*bb;
    return sum;
}


int main(){

int a,b,sums;
a=5;b=6;



printf("%d",sum(a,b,sums));

return 0;
}
