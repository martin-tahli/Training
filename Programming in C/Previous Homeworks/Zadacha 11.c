#include <stdio.h>
#include <stdbool.h>
//Създайте С програма, която калкулира стойността на покупки в магазин за хранителни стоки. Клиентът може да закупи различна комбинация от продукти.
// В магазина има следните налични продукти и цени:
//Домати- 4.5 лв.за килограм, Брашно 1.80 лв. за килограм,
//Кисело мляко - 0.50 лв. за брой, Сладолед на фунийки 0.60 лв. броя
//Бонбони 1.50 лв. за килограм, Близалки 0.15 лв. за брой



int main(){

double tomatoes=4.5, flour=1.8, yoghurt=0.5,ice_cream=0.6,candy=1.5, lolipop=0.15, balance=0, amount=0;
int choice=0;

printf("Wellcome to our shop!\n");


while(true){
    printf("What would you like today? \n");
    printf("1)Tomatoes\n");
    printf("2)Flour\n");
    printf("3)Yoghurt\n");
    printf("4)Ice-cream\n");
    printf("5)Candy\n");
    printf("6)Lolipop\n");
    printf("7)Thats it\n");
    printf("Enter choice:");
    scanf("%d", &choice);

    switch(choice){
    case 1:
    printf("Enter Amount: ");
    scanf("%lf", &amount);
    balance=balance+(amount*tomatoes);
    break;

    case 2:
    printf("Enter Amount: ");
    scanf("%lf", &amount);
    balance=balance+(amount*flour);
    break;

    case 3:
    printf("Enter Amount: ");
    scanf("%lf", &amount);
    balance=balance+(amount*yoghurt);
    break;

    case 4:
    printf("Enter Amount: ");
    scanf("%lf", &amount);
    balance=balance+(amount*ice_cream);
    break;

    case 5:
    printf("Enter Amount: ");
    scanf("%lf", &amount);
    balance=balance+(amount*candy);
    break;

    case 6:
    printf("Enter Amount: ");
    scanf("%lf", &amount);
    balance=balance+(amount*lolipop);
    break;

    case 7:
    printf("Goodbye!");
    printf("Balance of today is:\t%.0f",balance);
    exit(0);
}
}









return 0;
}
