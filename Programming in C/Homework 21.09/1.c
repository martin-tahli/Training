//Напишете функция, която печата низ, като принтирате всеки
//символ поотделно. Указателя към началото му е подаден като аргумент на
//функцията void printstr(char *s); Не забравяйте, низът винаги
//завършва с знак за терминираща нула '\0', затова проверката в цикъла, който
//принтира всеки символ, трябва да е докато не се стигне този знак.

#include <stdio.h>
void printstr(char *s)
{

    while(*s!='\0')
    {
        printf(" %c ",*s );
        s+=1;
    }
}

int main(){
char s[100];

//fgets(s,100,stdin);
gets(s);

printstr(s);

return 0;
}