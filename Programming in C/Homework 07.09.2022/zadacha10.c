/*Задача 10. Напишете програма, която по зададено естествено число n, отпечатва сумата от
първите n члена на редицата
1, 1/2, 1/3, …. 1/n 
*/
#include<stdio.h>


int main(){
int i,n;
double sum=0;

printf("enter N:");
scanf("%d",&n);

for(i=1;i<n;i++){
sum+=1.0/i;
}
printf("%f",sum);

return 0;
}
