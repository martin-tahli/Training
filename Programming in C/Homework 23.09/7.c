//Напишете програма, която печата броя на уникалните редове в
//бинарна матрица, съставена само от единици и нули



#include <stdio.h>
#include <time.h>
#define size 10

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
            // scanf("%d",&arr[i][j]);
            arr[i][j]=(rand() % 2);
        }
    }
// searching for unique rows


     for(int i=0; i<size; i++)
    {
        int flag=0;

        //check for unique rows

        for(int j=0; j<i; j++)
        {
            flag=1;

            for(int k=0; k<=size; k++)
            if(arr[i][k]!=arr[j][k])
                flag=0;

            if(flag==1)
            break;
        }

        //if no row is unique
        if(flag==0)
        {
            //print the row
            for(int j=0; j<size; j++)
                printf(" %d " ,arr[i][j]);

        }
        puts("");
    }




//printing the matrix

//    for(int i=0;i<size;i++)
//    {
//        for(int j=0;j<size;j++)
//        {
//           printf(" %d ", arr[i][j]);
//        }
//        puts("");
//    }
//


return 0;
}
