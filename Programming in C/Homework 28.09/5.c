//
//Напишете програма за търсене на определен елемент в даден масив,
//използвайки указатели.

#include <stdio.h>


int main(){

int ar[]={1,2,3,4,5,6};
int *p=ar;
int counter=0;
int n;
printf("Enter number to be found ");
scanf("%d",&n);

while(*p!=n)
{

counter++;
p++;

}
printf("number %d is found at index %d ", *p, counter+1);


return 0;
}
