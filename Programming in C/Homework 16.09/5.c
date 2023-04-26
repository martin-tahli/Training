/*Напишете програма, която принтира уникалните елементи от
масив с цели числа, въведени от клавиатурата. За целта, някои
от числата трябва да се повтарят.
*/

#include <stdio.h>

int main(){

int arr[10]={};
int lenght;
int curElem;
int count;
lenght=sizeof(arr)/sizeof(arr[0]);

for(int i=0;i<10;i++){
scanf("%d",&arr[i]);
}

for(int i =0;i<lenght;i++)
{
count=0;
curElem=arr[i];
    for(int j=0;j<lenght;j++)
    {

            if(curElem==arr[j])
            {
            count++;
            }
    }
    if(count==1)
    {
    printf(" %d ",curElem);
    }
}



return 0;
}
