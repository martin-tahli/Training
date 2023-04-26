//
// Дефинирайте структура с 4 полета (int. char[10], double, enum),
//  направете масив от 20 структури и ги попълнете. Изведете масива
//  от структури на стандартния изход в CSV формат
#include <stdio.h>
#include<string.h>
#define size 2
typedef enum {first,second,third,forth}enm;

struct fields
{
    int a;
    char s[10];
    double d;
    enm e;
}f[size];

void input(struct fields* s1,int a, char *s,double d)
{
    s1->a=a;
    strcpy( s1->s, s );
    s1->d=d;

}
void print(struct fields*s1)
{
    printf("integer : %d\n",s1->a);
    printf("string : %s\n",s1->s);
    printf("double : %.3lf\n",s1->d);
    printf("Enum : %d\n",s1->e);
}
int main(){

int ee=0;
    for(int j=0;j<size;j++)
    {
    int a;char s[10];double d;
        puts("Type int");
        scanf("%d",&a);
        puts("Type string");
        scanf("%s",&s);

        puts("Type double");
        scanf("%lf",&d);

        puts("Type enum");
        scanf("%u",&ee);

        input(&f[j],a,s,d);
        f[j].e=ee;
    }
for(int i=0;i<size;i++)
{
    print(&f[i]);
    printf("%u",f[i].e);
}

return 0;
}
