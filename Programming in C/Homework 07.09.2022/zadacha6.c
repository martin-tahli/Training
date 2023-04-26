/*6. Да се изведат първите N числа на една редица (аритметична прогресия), ако са дадени
първият член на редицата и разликата между първите два елемента. Да се напише програма.
Числата са на вход.*/

#include <stdio.h>


int main(){
int n,i ;
float razlika;
printf("enter N:");
scanf("%d",&n);
printf("Difference :");
scanf("%f",&razlika);

double chislo=1;

for (i=0;i<n;i++){
printf("%f \n",chislo);
chislo+=razlika;

}

return 0;
}
