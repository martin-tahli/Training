/*Напишете функция reverse(s), която обръща символния низ
s. Използвайте я, за да напишете програма, която преобръща входа си ред
по ред.
*/
#include  <stdio.h>
#include <string.h>

void reverse(char *str){
int i;
char revstring[100];
int endc;


    while(str[i]!='\0'){
    i++;
    endc=i-1;
    }

	for(i = 0; i <100; i++)
    {
    revstring[i]=str[endc];
    endc--;
    }
   revstring[i]='\0';
   printf("%s\n",revstring);

}


int main(void)

{
char str[100];//={"hello"};

while(1){

gets(str);
reverse(str);
}
  return 0;
 }

