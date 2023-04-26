//Използвайте Задача 2, за да напишете програма, която проверява
//дали съобщението не е палиндром. Палиндром е съобщение, в което
//буквите от ляво на дясно са същите като от дясно на ляво

#include <stdio.h>


int main()
{
char c[100];
char *ptrB,*ptrE;
int flag=0;
scanf("%s",&c);
int lenght=strlen(c);

ptrB=c;
ptrE=c;


for(int i=0;i<lenght-1;i++)
{
    ptrE++;
}

for (int i = 0; i < lenght / 2; i++) {

        if(*ptrB==*ptrE)
        {
            flag=1;
        }
        else flag=0;

        ptrB++;
        ptrE--;
    }

    if(flag==1)
    {
        printf("palindrom\n");
    }
    else printf("not palindrom\n");
printf("%s",c);

return 0;
}
