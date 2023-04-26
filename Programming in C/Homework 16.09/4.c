/*4. Напишете програма, която приема 10 цели числа от
клавиатурата, запазва ги в масив и ги принтира в обратен ред.*/


#include <stdio.h>


int main(){

int arr[10];
int a;
int i,j;


for (i=0;i<10;i++){
scanf("%d",&arr[i]);
}

    for(i=9;i>=0;i--)
        {
        printf(" %d ",arr[i]);
        }

return 0;
}
