//Напишете функция, която изчислява произведението на
//числата от 1 до 30.
//Задача 6. Напишете функция, която прави същото, както в задача
//5, но е рекурсивна.

#include <stdio.h>
long long unsigned fact(long long unsigned size)
{ int fact=1;
    for (int i=1;i<size;i++)
    {
        fact*=i;
    }
    return fact;
}

long long unsigned recFact(long long unsigned size)
{
  if (size == 0)
    return 1;
  else
    return(size * recFact(size-1));
}

int main(){

printf("%lld\n",fact(10));
printf("%lli",recFact(10));




return 0;
}
