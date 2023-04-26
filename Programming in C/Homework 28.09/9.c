//9. Напишете програма, която разменя две числа, използвай указатели


#include <stdio.h>


int main(){
int a=4;
int b=3;
int temp;
int *aa=&a;
int *bb=&b;

temp=*aa;
*aa=*bb;
*bb=temp;

printf(" %d   %d ",a,b);

return 0;}
