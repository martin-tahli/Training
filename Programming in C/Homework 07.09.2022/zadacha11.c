/*11. Да се напише програма, която по дадено цяло положително число, проверява дали това е
просто или не е.
*/


#include <stdio.h>

int main(){
int number;

printf("enter Number\n");
scanf("%d",&number);

for (int i = 2; i <= number / 2; ++i)
{
    if (number%i==0){
    printf("SLOJNO");break;
    }
    else
    {
    printf("PROSTO ");
    break;}
}

return 0;
}
