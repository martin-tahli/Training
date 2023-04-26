//
//. Напишете програма, която събира две числа, използвайки указатели


#include <stdio.h>


int main(){

int a=4;
int b=3;
int result=0;
int *aa=&a;
int *bb=&b;

result=*aa+*bb;

printf("%d",result);

return 0;
}
