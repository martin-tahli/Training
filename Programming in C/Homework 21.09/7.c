//
//Напишете функция void reverse(char src[], char dest[]),
//която обръща низа char src[ ], като същевременно го копира в char dest[].
//Принтирайте двата низа на екрана, за да могат да бъдат сравнени.


#include <stdio.h>
static int size=10;
void reverse(char src[], char dest[])
{
        for(int i=0;i<size;i++)
        {
            dest[i]=src[i];
        }
    int lastE=strlen(src);
        for(int i=0;i<lastE/2;i++)
        {
            char temp;
            temp=src[i];
            src[i]=src[lastE-i-1];
            src[lastE-i-1]=temp;
        }

}
void print(char src[], char dest[])
    {
        printf("\n");
    for (int i=0;i<size;i++)
    {
    printf("%c",src[i]);
    }
    printf("\n");
    for (int i=0;i<size;i++)
    {
    printf("%c",dest[i]);
    }
}

int main(){
char src[size];
char dest[size];


gets(src);


reverse(src,dest);
print(src,dest);

return 0;
}
