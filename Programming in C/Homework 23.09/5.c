
// Задача 5*. Напишете програма, която проверява дали дадена матрица е identity matrix - матрица с размер (N x N),
//където само елементите в главния диагонал са единици, а всички останали елементи са нули.



#include <stdio.h>
#include <stdlib.h>


int main() {

    int row = 0;
    int col = 0;
    int condition = 0;

    printf("Please enter two numbers for rows and cols: ");
    scanf("%d %d", &row, &col);


    int array[10][10] = {};

    if (row != col) {
        printf("The matrix is not an identity matrix");
       exit(1);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (i == j && array[i][j] != 1)
            {
                condition = 1;
            }
        }
    }
 printf("\n");
    if (condition == 0)
    {
        printf("not an identity matrix");
    }
    else printf("an identity matrix");
    return 0;
}
