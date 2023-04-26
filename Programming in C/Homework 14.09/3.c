//3. Напишете функция, която връща резултат (а+в)*4

#include <stdio.h>



int sum(int a,int b)
{

return (a+b)*4;
}

int main(){
int a,b;
printf("Enter a\n");
scanf("%i", &a);
printf("Enter b\n");
scanf("%i", &b);

printf("%i",sum(a,b));


return 0;
}

