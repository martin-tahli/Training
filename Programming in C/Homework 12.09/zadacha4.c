/*4. Напишете програма, която копира входа си на изхода, като
замества всеки низ повече от една шпации, с една единствена
шпация. */

#include <stdio.h>



int main(){
char c;
char lastc;
while((c = getchar()) != EOF)
  {
    if(c == ' ')
    {
        if(lastc!=' ')
        putchar(c);
    }
    else
      putchar(c);
    lastc=c;
  }

return 0;
}
