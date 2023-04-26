/*9) Направете на нула битовете в числа, намиращи се на
позиции между 3 и 7.*/


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


int a=15;
convertToBinary(a);
printf("\n");
int mask = 1<<2;


int temp = ~mask;

a = a & temp;
convertToBinary(a);
mask = mask << 1;




return 0;
}
