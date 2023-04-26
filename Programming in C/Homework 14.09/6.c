// Напишете програма на С, която чрез функция да обръща
//десетични числа в двоични.

#include<stdio.h>


int binary(int n)
{
int  c, k;
    printf("%d in binary number system is:\n", n);
    for (c = 31; c >= 0; c--)
    {
    k = n >> c;

    if (k & 1)
    printf("1");
    else
    printf("0");
    }

    printf("\n");

}

int main(){

    binary(155);

return 0;
}
