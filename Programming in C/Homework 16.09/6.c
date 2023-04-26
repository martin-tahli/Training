/*Напишете програма, която да брои колко пъти се среща едно
число в даден масив от цели числа. Масива трябва да бъде
въведен от клавиатурата. Принтирайте резултатите.*/

#include <stdio.h>

int main(){
int count=0;
int i,j;
int arr[10]={};
int curElem;

for (i=0;i<10;i++){
scanf("%d",&arr[i]);
}

for(i=0;i<10;i++){
count=0;
curElem=arr[i];

    for(j=0;j<10;j++)
    {
        if(curElem==arr[j])
        {
        count++;
        }

    }

printf("\nElement: %d \t is found: %d times\n",curElem,count);


}




return 0;}
