//Направете функцията :
//void copy(char *to, char *from), която копира една
//последователност от символи в друга. Разпечатайте на екрана и
//двете последователности, за да могат да бъдат сравнени.

#include <stdio.h>
static int size=10;

void copy(char *from, char *to)
{
 while(*(to++) = *(from++));
}




int main()
{   char c[size];
    char d[size];

    char *from=c;
    char *to=d;

    fgets(c,size,stdin);

    copy(from,to);

    printf("copied string = %s\n", d);
    printf("original string = %s\n", c);

    return 0;
}
