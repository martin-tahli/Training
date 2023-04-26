//. Напишете програма, която да изчисли факториал на дадено число,
//използвайки указатели.

#include <stdio.h>

int main(){

int temp=1;

int *p=&temp;


for(int x=1;x<=5;x++)
{

        *p=*p * x;

}
printf("%d",*p);
return 0;}
