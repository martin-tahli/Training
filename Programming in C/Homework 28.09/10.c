//Напишете програма, която обръща стринг, въведен от клавиатурата,
//използвайки указатели.


#include<stdio.h>
#include <string.h>

int main(){
char str[]="Hellso";
char revstr[100];


char *plas=&str[strlen(str)-1];

for(int i=0;i<strlen(str);i++)
{
revstr[i]=*plas;
plas--;

revstr[i+1]='\0';
}

printf("%s",revstr);



return 0;}
