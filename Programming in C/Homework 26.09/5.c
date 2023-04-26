//Пренапишете алгоритъма за сортиране без да използвате
//инкрементиращи променливи.
//void sort ( int a[], int n){
//int i = 0, j = 0, temp = 0;
//for ( i = 0; i < n - 1; ++i ){
//for ( j = i + 1; j < n; ++j ){
//if ( a[i] > a[j] ) {
//temp = a[i];
//a[i] = a[j];
//a[j] = temp;
//}
//}
//}

#include <stdio.h>


void sort2(int *a,int n)
{
    int i = 0, j = 0, temp = 0;
    int *ptr=a;


    for ( i = 0; i < n - 1; ++i )
    {
        for ( j = i + 1; j < n; ++j )
        {
           if (*(ptr + j) < *(ptr + i))
           {

                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }

    }

}
}


int main(){

int arr[]={1,2,6,8,3,4,8,9,5};
int n=9;

sort2(arr,n);
for(int i=0;i<n;i++)
{
    printf(" %d  ",arr[i]);
}


return 0;
}
