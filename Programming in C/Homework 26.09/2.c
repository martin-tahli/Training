//Напишете програма, която чете съобщение от клавиатурата, след
//което го принтира в обратен ред, използвайки адресна аритметика.
//

#include <stdio.h>


int main()
{
char c[100];
char *ptrB,*ptrE;
char curElem;
scanf("%s",&c);
int lenght=strlen(c);

ptrB=c;
ptrE=c;


for(int i=0;i<lenght-1;i++)
{
    ptrE++;
}

for (int i = 0; i < lenght / 2; i++) {
        curElem = *ptrE;
        *ptrE = *ptrB;
        *ptrB = curElem;
        ptrB++;
        ptrE--;
    }

printf("%s",c);

return 0;
}
