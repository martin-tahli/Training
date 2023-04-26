//. Напишете функция, която връща резултат a*2 + b*c
#include <stdio.h>



int sum(int a,int b,int c)
{

return a*2+b*c;
}

int main(){
int a,b,c;

printf("Enter a\n");
scanf("%i", &a);

printf("Enter b\n");
scanf("%i", &b);

printf("Enter c\n");
scanf("%i", &c);

printf("%i",sum(a,b,c));


return 0;
}

