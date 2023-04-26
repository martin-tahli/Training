/*Напишете програма на С, която съдържа 2 функции.
1.Първата смята лице на правоъгълен триъгълник.
2.Втората използва лицето на триъгълника, за да сметне лице на
четириъгълник със същите дължини на страните, като раменете на
триъгълника.
Напишете прототипите на функциите най-отгоре, а телата им под мейн
функцията.
*/


#include <stdio.h>
double   Area;

double area();

double square();


int main(){


square(5,5);

return 0;
}

double area(double a,double b)
{
  Area=(a*b)/2;
printf("Area of triangle is :%lf\n",Area);
}
double square(a,b)
{
double arean;
area(a,b);
    arean=Area*2;
printf("Area of square is :%lf\n",arean);
}
