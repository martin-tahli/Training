/*Задача 15. Използвайте статична локална променлива, за да постигнете
същото поведение, описано в задача 14.*/


#include <stdio.h>


void Increment()
{
static int Val=0;
   Val++;
   printf("%d",Val);
}


void main()
{


   for (int i=0;i<3;i++){

   Increment(i);

   }
}


