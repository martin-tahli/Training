/*10. Представете си, че имате фирма за отдаване на каравани и кемпери под
наем, за която трябва да разработите софтуер. Вие сте малка фирма и имате
общо 3 каравани на цена 90 лв. на ден и 3 кемпера на цена 100 лв. на ден.
Декларирайте променливи за броя на караваните, цената на караваните, броя на
кемперите и цената им. Направете меню, което пита клиента каравана или
кемпер ще иска. Направете променлива, в която да се събират парите, които
клиента дължи на компанията. Принтирайте резултата.*/


#include <stdio.h>
#include <stdbool.h>


int main(){

double Karavana=3,Kemper=3;
double cenaKaravana=90,cenaKemper=100;
double balance=0, amount=0,days=0;

int choice=0;

while(true){
    printf("What do you need Caravan or Camper or both ?\n");
    printf("1)Caravan\n");
    printf("2)Camper\n");
    printf("3)Both\n");
    printf("4)Nothing\n");
    printf("Enter choice:");
    scanf("%d", &choice);

    switch(choice){
    case 1:
    printf("Enter Amount: ");
    scanf("%lf", &amount);
    Karavana-=amount;
    if(amount>3 || Karavana<0 || Kemper<0){printf("\nWe dont have that much units \n");exit(0);}
    printf("For how many days would u like: ");
    scanf("%lf",&days);
    balance=balance+(amount*cenaKaravana*days);

    break;

    case 2:
    printf("Enter Amount: ");
    scanf("%lf", &amount);
    Kemper-=amount;
    if(amount>3 || Karavana<0 || Kemper<0){printf("\nWe dont have that much \n");exit(0);}
    printf("For how many days would u like: ");
    scanf("%lf",&days);
    balance=balance+(amount*cenaKemper*days);
    break;

    case 3:
    printf("Enter Amount: ");
    scanf("%lf", &amount);
    Karavana-=amount;
    Kemper-=amount;
    if(amount>3 || Karavana<0 || Kemper<0){printf("\nWe dont have that much \n");exit(0);}
    printf("For how many days would u like: ");
    scanf("%lf",&days);
    balance=balance+(amount*cenaKaravana*cenaKemper*days);
    break;

    case 4:
    printf("Goodbye!");
    printf("Balance of today is:\t%.0f",balance);

    case 5:
    exit(0);

    }


}

return 0;

}
