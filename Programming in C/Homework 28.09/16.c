//
//Напишете функция-аналог на стандартната С функция strcmp(), като
//използвате указатели.

#include <stdio.h>
#include <string.h>

int my_strcmp(const char *a, const char *b)
{
    while (*a && *a == *b) { ++a; ++b; }
    return (int)(unsigned char)(*a) - (int)(unsigned char)(*b);
}

int main(){
char s[]="hello";
char d[]="hellasfafos";

printf("%d",my_strcmp(s,d));


return 0;}
