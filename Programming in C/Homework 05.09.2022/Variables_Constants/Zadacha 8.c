/*Задача 8*. Напишете програма, която пресмята колко символа има в един
низ преди края на низа, обозначен със символа ‘\0’. Как трябва да изглежда
програмата:
1. Декларираме и инициализираме един низ - char s[ ] = “Hi”;
2. Декларираме и инициализираме променлива i, която ще увеличаваме
всеки път, когато искаме да видим следващия символ от низа “Hi”.
3. Принтираме съответната буква от низа printf(“%c”, s[i]);
4. Принтирайте броя на буквите в низа.*/


#include <stdio.h>
#include<string.h>



int main(){


char s[]="Hello";

int i=0;

printf("symbols:%d \n",strlen(s));

for ( i;s[i]!='\0';i++)
{
    printf("%c ",s[i]);
}



return 0;
}