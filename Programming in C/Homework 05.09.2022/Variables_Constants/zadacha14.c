/*Зада 14. Напишете глобална променлива, която увеличаваме с 1 във
функция void test(). Извикайте функцията три пъти test() от main()
принтирайте стойността на глобалната променлива.*/



#include <stdio.h>

int Val;
void Increment()
{
   Val++;
   printf("%d",Val);
}


void main()
{
int j=5;

   for (int i=0;i<3;i++){

   Increment(j);

   }
}


