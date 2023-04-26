//
//Напишете програма, която конкатери два стринга, използвайки указатели

#include <stdio.h>

int main(){

char c[]="Hello";
char d[]=" Hello c";
char result[100];
char *cc=c;
char *dd=d;
int i=0;

int results=strlen(d)+strlen(c);


while(*dd!='\0'){

    if(*cc!='\0')
    {
        result[i]=*cc;
        cc++;
    }

    else
    {
        result[i]=*dd;
        dd++;
    }
i++;
}


result[results+1]='\0';
printf("%s",result);

return 0;
}

