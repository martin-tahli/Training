//Напишете програма, в която информацията да бъде съхранявана
//в структура, описваща автомобил. Входната информация трябва бъде
//въведена от потребителя, като напишете меню с въпроси към него.
//Принтирайте въведената информация за описание на автомобила.

#include <stdio.h>

struct Car{
    char brand[10];
    char model[10];
    char color[10];
    int year;
    float CC;
};
void print(struct Car* car)
{
    printf("Car brand: %s\n",car->brand);
    printf("Car model: %s\n",car->model);
    printf("Car color: %s\n",car->color);
    printf("Car year: %d\n",car->year);
    printf("Car CC: %.2f\n",car->CC);
}


int main()
{
struct Car firstCar;
puts("Car brand ?");
scanf("%s",&firstCar.brand);
puts("Car model ?");
scanf("%s",&firstCar.model);
puts("Car color ?");
scanf("%s",&firstCar.color);
puts("Car year ?");
scanf("%i",&firstCar.year);
puts("Car CC ?");
scanf("%f",&firstCar.CC);

print(&firstCar);

return 0;
}
