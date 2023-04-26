//Напишете програма, която сумира редовете и колоните на въведена
//от потребителя матрица. Разпечатайте матрицата и резултатите в конзолата.

#include <stdio.h>


int main(){
int arr[10][10]={};
int r,c;
puts("input rows and cols");
scanf("%d",&r);
scanf("%d",&c);
int total =0;
int sum_rows=0;
int sum_cols=0;

puts("enter teh matrix");
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
            scanf("%d",&arr[i][j]);
            }
            puts("");
        }

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
            printf(" %d ",arr[i][j]);
            }
            puts("");
        }
//calc rows and cols

        for(int i = 0; i < r; i++)
        {

        sum_rows=0;
        sum_cols=0;
            for(int j = 0; j < c; j++)
            {

            sum_rows+=arr[i][j];
            sum_cols+=arr[j][i];

            }
            printf("sum of row N: %d and sum is %d \n",i,sum_rows);
            printf("\nsum of cols is %d \n",sum_cols);

        }


return 0;
}
