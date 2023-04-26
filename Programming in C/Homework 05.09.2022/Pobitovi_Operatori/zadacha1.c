/*1)Направете побитовите операции върху целите числа 3 и 5 в main().
Покажете резултата с функцията printf(“%d”, res);
2) Какъв ще бъде резултата от следната операция: а = а ^ a; ?
*/
#include<stdio.h>


int main(){

int and,or,xor,a=3,b=5;

and=a&b;
or=a|b;
xor=a^b;

printf("and:%d,\tor:%d,\txor:%d\t",and,or,xor);
a=a^a;
printf("a:%d",a);
return 0;
}
