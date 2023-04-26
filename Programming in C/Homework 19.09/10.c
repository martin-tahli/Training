
/*Напишете функция с прототип my_swap(а, b), която разменя
стойностите на две цели числа без да използва спомагателна променлива
(например: *a = *a + *b; *b = *a - *b; *a = *a - *b).
*/


#include <stdio.h>
int my_swap(int а, int b);

int main(){
int a=10;
int b=5;

my_swap(a,b);
//printf("%d %d ", my_swap(a,b));
return 0;
}

int my_swap(int a, int b)
{
int* g=&a;
int* c=&b;

*g = *g + *c;
*c = *g - *c;
*g = *g - *c;

printf("%d , %d ", *g , *c);
//return *g , *c;
}
