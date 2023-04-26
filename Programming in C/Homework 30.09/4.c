//Задача 4. Напишете функция void sort_arr(void *A, int n, int dir, ftype fp),
//където А е обикновен масив от цели числа, n - размера на масива, dir -
//посоката, в която да бъде сортиран масива, и ftype - указател към функция,
//която приема масив, неговия размер и в каква посока да бъде сортиран
//входния масив. ftype трябва да сортира масива във възходящ или низходящ
//ред в зависимост от третия параметър на функцията. Принтирайте изходния
//и резултатни масиви.

#include <stdio.h>
typedef void(*ftype) (void*A,int n,int dir);


void ascending(void *A, int n)
{
    int *ptr=A;
    int temp;
        for(int i =0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(*(ptr+i) > *(ptr+j))
                {
                temp=*(ptr+i);
                *(ptr+i)=*(ptr+j);
                *(ptr+j)=temp;
                }
            }
        }
}
void descending(void *A, int n)
{
     int *ptr=A;
    int temp;
        for(int i =0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(*(ptr+i) < *(ptr+j))
                {
                temp=*(ptr+i);
                *(ptr+i)=*(ptr+j);
                *(ptr+j)=temp;
                }
            }
        }
}
void sort_arr(void *A, int n, int dir, ftype fp)
{
    switch(dir)
    {
        case 1:fp=ascending;break;
        case 2:fp=descending;break;
        default:puts("invalid ");
    }
    fp(A,n,dir);
}


int main(){

int arr[10]={1,6,9,4,8,0,2,5,8,2};
int size=sizeof(arr)/sizeof(arr[0]);
int choice;
puts("Choose 1 for Ascending order of the array or choose 2 for Descending order");
scanf("%d",&choice);

ftype fp=NULL;

sort_arr(arr,size,choice,fp);

for(int i=0;i<size;i++)
{
printf(" %d ",arr[i]);
}



return 0;}
