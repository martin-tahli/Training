//Напишете програма, която намира под-матрица с максимален размер
//в дадена бинарна матрица, съставена само от нули и единици. Пример:

#include <time.h>
#include <stdio.h>
#define bool int
const int size =5;


//locating where it is
int min(int a, int b, int size)
{
int m = a;
if (m > b)
    m = b;
if (m > size)
    m = size;
return  m;
}


int main()
{
time_t t;
int M[size][size];
int i,j;
int S[size][size];
int max_of_s, max_i, max_j;


//fill the matrix
 srand((unsigned) time(&t));

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            M[i][j]=(rand() % 2);
        }
    }


for(i = 0; i < size; i++)
    S[i][0] = M[i][0];


for(j = 0; j < size; j++)
    S[0][j] = M[0][j];


for(i = 1; i < size; i++)
{
    for(j = 1; j < size; j++)
    {
    if(M[i][j] == 1)
        S[i][j] = min(S[i][j-1], S[i-1][j],
                        S[i-1][j-1]) + 1;
    else
        S[i][j] = 0;
    }
}


max_of_s = S[0][0]; max_i = 0; max_j = 0;
for(i = 0; i < size; i++)
{
    for(j = 0; j < size; j++)
    {
    if(max_of_s < S[i][j])
    {
        max_of_s = S[i][j];
        max_i = i;
        max_j = j;
    }
    }
}

printf("Maximum size sub-matrix is: \n");
for(i = max_i; i > max_i - max_of_s; i--)
{
    for(j = max_j; j > max_j - max_of_s; j--)
    {
    printf("%d ", M[i][j]);
    }
    printf("\n");
}
puts("");
for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
           printf(" %d ", M[i][j]);
        }
        puts("");
    }


return 0;
}
