/*Напишете програма, която запълва масив от 20 елемента с
произволно избрани цели числа. За целта използвайте
функцията rand(). Въведете едно цяло число от
клавиатурата. Проверете дали въведеното число от
клавиатурата е намерено в масива. Принтирайте масива и
отговора дали числото е намерено в масива. */


#include <stdio.h>
#include <time.h>


int main(){
int a ;
int arr[20];
printf("enter number");
scanf("%d",&a);
int flag;
srand(time);

for(int i =0;i<20;i++){
arr[i]=(rand()%10+1);
printf(" %d ",arr[i]);

    if(arr[i]==a){
    flag =1;
    }

}


        if(flag==1){
        printf("\n Suvpadenie: %d \n",a);
        }
        else
        {
         printf("\nnqma suvpadenie s : %d \n",a);
        }

return 0;
}
