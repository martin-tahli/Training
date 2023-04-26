//Напишете обединение от число и низ, както и изброим тип за
//съдържанието на обединението. Напишете функция, която получава
//указател към обединението и изброимия тип и извежда съответно низ или
//число.
#include<stdio.h>
#include <string.h>


union first
{
    int count;
    int num;
    char str[20];
};

void func(union first* f,int num, char str[])
{
    f->num=num;
    printf("number: %d\t",f->num);

    strcpy(f->str,str);
    printf("string %s\t  ",f->str);

    f->count=strlen(f->str);
    printf("counter %d\t  ",f->count);
}

int main()
{
union first f;
int num;
char sstr[20];

printf("enter numb\n");
scanf("%d",&num);
printf("enter string\n");
scanf("%s",&sstr);

func(&f,num,sstr);

return 0;
}
