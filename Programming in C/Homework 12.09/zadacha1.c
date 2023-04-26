/*Пребройте символите, подавани на конзолата, с функцията
getchar();*/


#include <stdio.h>


int main(){
int i=0;
char c;

while(c=getchar()!=EOF)
{
++i;
}
printf("number of chars is %d",i);





return 0;

}
