/*Напишете програма, която запълва масив от 20 елемента с
произволно избрани стойности. За целта използвайте функцията
rand(). Намерете най-голямото число в масива. Принтирайте
намереното число и масива.*/

#include <stdio.h>
#include <time.h>

int main (){
int arr[20];
srand(time);
int a;
for(int i=0;i<20;i++){
arr[i]=(rand()%50+1);
if(a<arr[i]){a=arr[i];}
printf(" %d ", arr[i]);
}
printf("\n nai golqmoto chislo e : %d \n",a);

return 0;
}
