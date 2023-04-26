/*Напишете три функции, които да правят изчисление по ваш
избор и да се извикват по следния начин:
 Main вика Ф1;
 Ф1 вика Ф 2;
 Ф2 вика Ф3;
Изнесете прототипите им в отделен .h файл.
*/


#include <stdio.h>
#include "9.h"

int main(){
func(4,2);
return 0;
}


double func3(double a,double b)
{
double result;
result=a*b;
printf("Func 3's result :%lf\n",result);
}
double func(double a,double b)
{
double result;
result=a+b;

printf("Func 1's result :%lf\n",result);
func2(a,b);
}
double func2(double a,double b)
{
double result;
result=a-b;
printf("Func 2's result :%lf\n",result);
func3(a,b);
}
