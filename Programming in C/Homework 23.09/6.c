//Напишете програма, която търси дадено число в сортирана по
//редове матрица. Генерирайте елементите на матрицата с rand(). Принтирайте
//матрицата и въведете от клавиатурата търсеното число. Покажете позицията
//му.

#include <stdio.h>
#include <time.h>

const int size =5;

int main(){
int arr[size][size];
time_t t;
int elem;


 srand((unsigned) time(&t));
//fill the arrtrix

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            arr[i][j]=(rand() % 10);
        }
    }
//sort
    for(int i=0;i<size;i++)
    {
        int temp=0;
        for(int j=0;j<size;j++)
        {
                for (int k = (j + 1); k < size; ++k)
                {
                        if (arr[i][j] > arr[i][k]) /* sorting in the ascending order */
                         {
                          temp = arr[i][j];
                          arr[i][j] = arr[i][k];
                          arr[i][k] = temp;
                        }
                }
        }
    }


//print the matrix
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
           printf(" %d ", arr[i][j]);
        }
        puts("");
    }


// entering the searched elem
puts("which element do u want to see if exists in the matrix");
scanf("%d",&elem);


for(int i=0;i<size;i++)
    {
        int temp=-1;
        for(int j=0;j<size;j++)
        {
            if(elem==arr[i][j]){
            temp=j;
            printf("Element has been found in possition: %d and row %d \n",temp,i);

            }

        }
        if(temp==-1)printf("Element has not been found in row %d \n",i);
    }




return 0;
}





