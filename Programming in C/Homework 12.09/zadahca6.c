/*Задача 6.Използвайте функцията getchar(), с която въвеждате
текст от клавиатурата, докато не подадете ЕОF. Текстът има
букви и цифри. Пребройте колко са въведените букви и колко са
въведените цифри. Определeте броя на цифрите в стринга, като
използвате оператор continue.
*/

#include <stdio.h>



int main(){
char c;
int numbs=0,chars=0;
int res=0;

while((c=getchar())!=EOF){

    if(c>='0'&&c<='9')
    {
    ++numbs;continue;
    }

    if(c>='a'&&c<='z'||c>='a'&&c<='z')
    {
    ++chars;
    }

}
printf("Numbers: %d\n Chars: %d \nSize of whole string without \\t\\n and spaces %d ",numbs,chars,chars+numbs);


return 0;
}
