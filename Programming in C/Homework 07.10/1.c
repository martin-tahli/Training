//Напишете обединение от три стойности: цяло число,
//число с плаваща запетая и низ. Инициализирайте отделните
//членове и ги изведете на екрана.
//
#include <stdio.h>

union test {
    int a;
    float b;
    char s[10];
};


int main(){

union test first;
first.a=1;
printf("integers %d\n",first.a);
first.b=3.14f;
printf("float %f\n",first.b);
first.s[0]='1';
first.s[1]='2';
first.s[2]='3';
first.s[3]='4';
first.s[4]='5';
first.s[5]='6';
first.s[6]='7';
first.s[7]='8';
first.s[8]='9';
first.s[9]='10';




printf("string %s\n",first.s);

return 0;
}
