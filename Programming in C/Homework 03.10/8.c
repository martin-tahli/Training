//Направете структура struct rect, която съдържа в себе си две
//точки. Създайте обект от тип тази структура наречен screen.
// Използвайте
//функцията makepoint за да зададете начална точка на екрана (0, 0)
//и крайна
//точка (15, 15). Запълнете пространството между тях с тирета.

#include <stdio.h>
struct point
{
    int x;
    int y;
};
struct rect
{
    struct point a;
    struct point b;
};


void makepoint(struct point* p,int x,int y)
{
    p->x=x;
    p->y=y;
}

int main()
{
struct rect rec;

makepoint(&rec.a,0,0);
makepoint(&rec.b,15,15);

    for(int i=rec.a.x;i<rec.b.x;i++)
    {
        for(int j=rec.a.y;j<rec.b.y;j++)
        {
            printf("-");
        }
        printf("\n");
    }

return 0;

}
