
/*Задача 11.Дефинирайте едномерен масив int с 10 елемента =
{100,90,80,70,60,50,40,30,20,10} Дефинирайте пойнтер, който ще сочи към
масива.
Достъпете 3 тия елемент от масива и му задайте стойност 5.
Достъпете 4 тия елемент и му задайте стойност 33.
Достъпете 5 тия елемент и го намалете със 7.
Достъпете 7 мия елемент и го увеличете с 10.
Достъпете 10 тия елемент и го умножете по 3.
Изпишете го по двата възможни начина и закоментирайте единия.
Принтирайте на екрана всички елементи на масива.*/

#include <stdio.h>


int main(){
int c[10]={100,90,80,70,60,50,40,30,20,10};
int* p=c;

p+=2;
*p=5;

for (int i =3;i<4;i++)
{p++;
*p=33;
p++;
*p=*p-7;
}
p+=2;
*p=*p+10;
p=p+3;
*p*=10;


for (int i=0;i<10;i++)
{
printf(" %d ",c[i]);
}
return 0;
}
