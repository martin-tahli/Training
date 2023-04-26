/*7. Да се изведат първите N числа на една редица (геометрична прогресия), ако са дадени първиятчлен на редицата и частното между първите два елемента. Да се напише програма.
Числата са на вход.
*/

#include <stdio.h>


int main(){
int n,i ;
float chastno;
printf("enter N:");
scanf("%d",&n);
printf("Difference :");
scanf("%f",&chastno);

double chislo=1;

for (i=0;i<n;i++){
printf("%f \n",chislo);
chislo*=chastno;

}

return 0;
}

