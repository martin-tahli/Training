/*7) Занулете всички битове на числата, намиращи се на четна
позиция.
*/


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
int i;
int mask = 2;
int temp = ~mask;

a = a & temp;
convertToBinary(a);
mask = mask << 2;




return 0;
}
