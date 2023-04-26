
/* Напишете функция void reverse(char s[]), която обръща
низа char s[].
*/
#include  <stdio.h>
#include <string.h>

void reverse(char s[])
{
int i, end;
char revstr[100];

    while(s[i]!='\0')
    {
    i++;
    end=i-1;
    }
    for (i=0;i<100;i++)
    {
        revstr[i]=s[end];
        end--;
    }
    revstr[i]='\0';

    printf("%s",revstr);
}

int main(){
char s[100];

gets(s);

reverse(s);

}
