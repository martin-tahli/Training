
//Напишете програма, която намира дължината на въведен от клавиатурата
//стринг, използвайки указатели.

#include <stdio.h>


int main(){
char s[100];

printf("Enter string ");

gets(s, 100, stdin);

//scanf("%[^\n]c",s);

int counter=0;
char *p=s;

while(*p!='\0')
{
p++;
counter++;
}
printf("lenght %d ",  counter);


return 0;
}
