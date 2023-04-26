
//Напишете програма, която да обедини два масива от цели
//числа, като ги сортира в низходящ
//ред и ги принтира.

#include <stdio.h>


int main(){
int arr[]={5,4,3,2,1};
int arr2[]={10,9,8,7,6};
int lenght=sizeof(arr)/sizeof(arr[0]);
int lenght2=sizeof(arr2)/sizeof(arr2[0]);
int arr3[lenght+lenght2];
int i=0;
int temp=lenght;


for (i=0;i<lenght;i++)
{
arr3[i]=arr[i];
}

for (i=0;i<lenght2;i++,temp++)
{
arr3[temp]=arr2[i];

}


for(int i = 0; i < lenght2+lenght; i++){
        int temp;
            for(int j = i + 1; j < lenght2+lenght; j++) {
                if(arr3[i] < arr3[j]) {
                    temp = arr3[i];
                    arr3[i] = arr3[j];
                    arr3[j] = temp;
                }
            }
}
for (i=0;i<lenght+lenght2;i++)
{
printf(" %d ",arr3[i]);
}

return 0;}
