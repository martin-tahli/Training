//Напишете програма, която събира две дистанции, които са
//изразени в километри, метри, сантиметри. Дистанциите трябва да бъдат
//въведени от потребителя. Принтирайте изходните и резултатната
//дистанция.

#include <stdio.h>
struct distance{
int km;
int m;
int cm;
};
int disCalc(struct distance* dis1,struct distance* dis2,struct distance* res)
{
    res->km=dis1->km+dis2->km;
    res->m=dis1->m+dis2->m;
    res->cm=dis1->cm+dis2->cm;
    while(res->m>1000)
    {
        res->km+=1;
        res->m-=1000;
    }
    while(res->cm>100)
    {
        res->m+=1;
        res->cm-=100;
    }

}
void input(struct distance* distance)
{
puts("KM ?");
scanf("%d",&distance->km);
puts("m ?");
scanf("%d",&distance->m);
puts("cm?");
scanf("%d",&distance->cm);

    puts("\n");
}
void print(struct distance* res)
{
    printf("result km : %d\n",res->km);
    printf("result m: %d\n",res->m);
    printf("result cm %d\n",res->cm);

}

int main()
{

struct distance d,d1,dres;

input(&d);
input(&d1);

disCalc(&d1,&d,&dres);
print(&dres);


    return 0;

}
