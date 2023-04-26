/*
Задача 16. Да се дефинира константата Пи (3.14159...) и да се напише
функция, която изчислява лицето на окръжност по даден радиус (Пи * R * R).
В main() да се извика горната функция с радиуси 1, 1.5, 13.
Задача 17.* Към задача 16 да се добави втора функция, която изчислява
лицето на елипса по зададени два параметъра ( Пи * A * B)
*/


#include <stdio.h>
#define CONST_PI (3.14159)

double lice(double R)
{
return CONST_PI*R*R;
}
double elipse(double A,double B)
{
return CONST_PI*A*B;
}

int main(){
double R,A,B;
int choice =0;

printf("Elipse (1) or Circle(2)?");

if(scanf("%d",&choice)==1)
{
printf("Enter A:",A);
scanf("%lf",&A);
printf("Enter B:",B);
scanf("%lf",&B);
printf("Elipse : %lf",elipse(A,B));
}

else
{
printf("Enter Radius:",R);
scanf("%lf",&R);
printf("%lf",lice(R));
}


return 0;
}
