/*Задача 7. Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF(Ctrl+D). Текстът да отпечатва
само входни редове, които са по дълги от 80 символа.*/

#include <stdio.h>

int main(){
char c;
int count;

while((c=getchar())!=EOF){

if (c!='\n'){
    count+=1;
    if(count>80){putchar(c);}
}
else{break;}
}



return 0;
}
