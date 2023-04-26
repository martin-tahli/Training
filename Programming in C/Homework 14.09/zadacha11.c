
/*Напишете програма, която да премахва всички коментари в
една С програма.
*/

#include <stdio.h>

void uncommend(char s[]){
int i, end;
char str[100];
//str[]=s[];
char spac=' ';
char c;
char d;
    for (i=0;i<100;i++)
    {
        c=s[i];
        if(c=='/')
        {
            //if((d=getc(c))=='*'){
           c=putchar(spac);
       // }
        }
    s[i]=c;
    }

printf("%s",s);
}



int main(){
char str[100];

fgets(str,100,stdin);


uncommend(str);
  //
//printf("%s",uncommend());



return 0;
}
