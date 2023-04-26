//Задача 10. Създайте структура диня с два елемента - диаметър и дебелина на кората заделете динамично с malloc()
// за масив от А на брой дини от сорт мелон и попълнете данните за диаметър между 15 и 140 см с функцията rand(),
//  за всяка една диня в масива и дебелина на кората между 0.5 и 3.5 см. Създайте структура диня с два елемента -
//  диаметър и дебелина на кората заделете динамично с malloc() за масив от В на брой дини от сорт пъмпкин и попълнете
//  данните за диаметър между 35 и 95 см с функцията rand(), за всяка една диня в масива и дебелина на кората между
//  0.3 и 0.9 см. Намерете средната големина на динята и средната дебелина на кората и ги съпоставете с тези от втория
//  масив. Изведете на екрана купчината от кой сорт е по добре да се купи. Изход: По-добре е да се купят ... дини с
//  диаметър ... сантиметра и кора с дебелина D см вместо ... дини с диаметър ... см и дебелина на кората D1 см.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Watermellon {
    int diameter;
    double thickness;

}Watermellon;

void inputWatermelon(Watermellon *numb,int diam, double thick)
{
    numb->diameter=diam;
    numb->thickness=thick;
}

void printWatermelon(Watermellon *numb)
{
    printf(" diameter %d \n",numb->diameter);
    printf(" thickness %lf \n",numb->thickness);
}


int main(){
int mellon;
int pumpkin;
int diam;
double thick;
time_t t;
double averageDiam=0;
double averageSkin=0;
double average;
double averageDiamP=0;
double averageSkinP=0;
double averageP;

    puts("enter amount of watermellons sort Mellon");
    scanf("%d",&mellon);

    Watermellon* mellons=(malloc(mellon*sizeof *mellons));

    puts("enter amount of watermellons sort Pumpkin");
    scanf("%d",&pumpkin);

    Watermellon* pumpkins=(malloc(pumpkin*sizeof *pumpkins));


    for(int i=0;i<mellon;i++)
    {   diam=0;
        thick=0;

        diam=rand()%140+15;
        thick=(( (double)rand() * ( 3.5 - 0.5 ) ) / (double)RAND_MAX + 0.5);

        inputWatermelon(&(mellons[i]),diam,thick);
        averageDiam=(averageDiam+mellons->diameter);
        averageSkin=(averageSkin+(mellons->thickness)*2);
    }
//printf(" %.2lf ",averageDiam);
    averageDiam/=mellon;
    averageSkin/=mellon;

    for(int i=0;i<pumpkin;i++)
    {   diam=0;
        thick=0;

        diam=rand()%95+35;
        thick=(( (double)rand() * ( 0.9 - 0.3 ) ) / (double)RAND_MAX + 0.3);
        averageDiamP=(averageDiamP+pumpkins->diameter);
        averageSkinP=(averageSkinP+(pumpkins->thickness)*2);

        inputWatermelon(&(pumpkins[i]),diam,thick);
        //printWatermelon(&(pumpkins[i]));
    }

averageDiamP/=pumpkin;
averageSkinP/=pumpkin;
average=averageDiam-averageSkin;
averageP=averageDiamP-averageSkinP;


if(average>averageP){

printf("Its better to buy Mellons with Diameter :%.2lf\t and skin with thickness: %.2lfcm \ninstead of Pumpkins with Diameter: %.2lf\t and skin thickness: %.2lf\n",averageDiam,averageSkin,averageDiamP,averageSkinP);
printf("they are overal better with : %.2lf\t than %.2lf\t\n",average,averageP);
}
else {

printf("Its better to buy Pumpkins with Diameter :%.2lf\t and skin with thickness: %.2lfcm instead of Melons with Diameter: %.2lf\t and skin thickness: %.2lf\n",averageDiamP,averageSkinP,averageDiam,averageSkin);
printf("they are overal better with : %.2lf\t than %.2lf\t\n",averageP,average);
}

//free(ptr);
return 0;
}
