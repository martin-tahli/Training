/*1. Клиент вложил А лв с месечна лихва В%. Как ще се променя тази вноска, ако клиентът не
тегли
пари през този период:
a/за 5 години;
б/за N години;
в/докато вноската стане по-голяма от С лв.
Да се напише програма. Числата са на вход.
*/

#include<stdio.h>


int main(){
int n,months;
float money;
float percent;
float fiveYears;
float nYears;
float untill;

printf("enter money & percent: \n");
scanf("%f %f",&money,&percent);

printf("enter N years: \n");
scanf("%d",&n);

printf("enter C money: \n");
scanf("%f",&untill);


fiveYears=money+(5*12*(money*percent)/100);
printf("Five Years: %f\n",fiveYears);

nYears=money+(n*12*(money*percent)/100);
printf("N years: %f\n",nYears);

float target=money;
while(target< untill) {
		months++;
		target+= money * percent / 100;
	}

printf("months:%d\n",months);


return 0;
}
