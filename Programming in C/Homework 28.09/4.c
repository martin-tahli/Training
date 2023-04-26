//Напишете програма, която обръща местата на елементите в един масив,
//използвайки указатели.
#include <stdio.h>


int main(){

int ar[]={1,2,3,4,5,6};
int *p=ar;
int *plas=&ar[5];
int temp;

while(p<=plas)

{

temp=*p;
*p=*plas;
*plas=temp;
plas--;
p++;
}

for (p=&ar[0];p<&ar[6];p++)
{
printf(" %d ", *p);

}

//
//for (int i=0;i<6;i++)
//{
//printf(" %d ", ar[i]);
//
//}
//

return 0;
}
