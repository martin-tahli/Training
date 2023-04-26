/*2. Започвайки тренировка спортист пробягал първия ден А км. Всеки следващ ден той
увеличавал дневната си норма с В% спрямо предишния ден. Какъв сумарен път ще пробяга
спортистът за :
а/10 дни;
б/N дни;
в/докато пробягания за ден път стане по-голям от Х км и на кой ден;
г/докато общо пробягания път стане по-голям от У км и за колко дни.
Да се напише програма. Числата са на вход.*/

#include<stdio.h>



int main(){
int n,dni;
float km;
float percent;
float tenDays;
float nDays;
float untillDay;
float untill;
float target=km;
float sum;
float wholeKm;
int i;
printf("enter km & percent: \n");
scanf("%f %f",&km,&percent);

printf("enter N days: \n");
scanf("%d",&n);

printf("enter C km: \n");
scanf("%f",&untill);

printf("Whole Target km: \n");
scanf("%f", &untillDay);

float kmTotal = km;
tenDays=km;
for(i =0;i<10;i++)
{
kmTotal+=kmTotal*percent/100;
tenDays+=kmTotal;
}

printf("Ten days: %f\n",tenDays);

kmTotal = km;
nDays=km;
for(i=0;i<n;i++){
kmTotal+=kmTotal*percent/100;
nDays+=kmTotal;

}
printf("N days: %f\n",nDays);


kmTotal = km;
	int dayCounter = 0;
	while(kmTotal < untill) {
		kmTotal += kmTotal * percent / 100;
		dayCounter++;
	}
printf("dni:%d\n",dayCounter);


float totalKm = km;
	kmTotal = km;
	int counter = 0;
	while(totalKm < untillDay) {
		kmTotal += kmTotal * percent / 100;
		totalKm += kmTotal;
		counter++;
	}
printf("dni:%d\n",counter);
return 0;
}
