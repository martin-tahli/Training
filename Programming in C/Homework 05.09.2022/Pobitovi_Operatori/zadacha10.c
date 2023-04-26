/*10) Премахнете всички битове на число след n-тия бит
включително*/

#include<stdio.h>
void convertToBinary(unsigned a)
{
    /* step 1 */
    if (a > 1)
        convertToBinary(a / 2);
    /* step 2 */
    printf("%d", a % 2);

}

int main(){
int n;
int a=15;
convertToBinary(a);
printf("\n");
scanf("%d",&n);
int mask = 1<<n-1;


int temp = ~mask;

a = a & temp;
convertToBinary(a);
mask = mask << 1;




return 0;
}

