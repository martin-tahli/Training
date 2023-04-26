/*Пребройте редовете, подадени чрез текст на конзолата.
Използвайте функцията getchar();
*/

#include <stdio.h>


int main(){
int i=0;
char c;
while(c=getchar()!=EOF){

if(c=='\n'){++i;}

}
printf("number of rows is %d",i);



return 0;
}
