//Напишете функцията double atof(char *s), която
//преобразува стринг в число с десетична запетая.
//Добавете проверка във функцията doble atof(char *s)
//дали числото е отрицателно, и ако е, добавете знака.
#include <stdio.h>

double atof(char* s) ;

int main() {

    double d ;
    char s[15];
    puts("Enter float number ");
    scanf("%s",&s);
    d=atof(s);
    printf("%lf ", d);

    return 0;
}
double atof(char *s)
{
static int floating = 0;
static double num = 0;
static int minus = 0;

    if(*s == '\0') {
        double endResult = num / floating;
        if (minus)
        {
            return endResult - 2 * endResult;
        }
        return endResult;
    }
    if (*s == '-')
    {
        minus++;
    }
    else if (*s == '.')
    {
        floating = 1;
    }
    else if(floating >= 1) {
        num = num * 10 + (*s - '0');
        floating *= 10;
    }
    else {
        num = num * 10 + (*s - '0');
    }
    return atof(s+1);
    }
