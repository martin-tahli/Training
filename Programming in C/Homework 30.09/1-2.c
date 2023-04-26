/*Задача 1. Направете две функции и извикайте желаната функция с указател към функция, съобразно знака, подаден от командния ред:
Пример: а.exe 20 + 3
#include <stdio.h>
#include <stdlib.h>
int fnPlus(int nA, int nB) { return(nA + nB); }
int fnMinus(int nA, int nB) { return(nA - nB); }
int ( * pfCalc ) ( int, int ) = NULL;

Задача 2. Добавете към горния код функции за умножение и деление.

*/
#include <stdio.h>
#include <stdlib.h>

typedef int (*ptrCalc)(int,int);

int plus(int nA, int nB)
{
return(nA + nB);
}

int minus(int nA, int nB)
{
return(nA - nB);
}

int multy(int nA, int nB)
{
return(nA * nB);
}

int divide(int nA, int nB)
{
return(nA / nB);
}


int main(int argc,char *argv[])
{

ptrCalc p= NULL;

switch(*argv[2])
{
    case '+': p=plus;    break;
    case '-': p=minus;   break;
    case '*': p=multy ;  break;
    case '/': p=divide ; break;
}

printf(" %d ",p(atoi(argv[1]),atoi(argv[3])));



return 0;
}

