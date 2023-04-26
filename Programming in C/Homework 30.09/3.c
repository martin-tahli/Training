/*Задача.3. Направете масив от указатели към функции по следния начин:
void add(){...}
void fun2(){...}
void fun3(){...}

void (*func_ptr[3])() = {fun1, fun2, fun3};
	Направете меню, с което да питате потребителя коя от горните функции иска да използва – събиране, изваждане, умножение и деление.
	След това попитайте за числата, които да участват в тази операция, и извикайте функцията, която да извърши желаната операция.
*/


#include <stdio.h>
#include <stdlib.h>

const int a;
const int b;

void plus(int nA, int nB)
{
printf("%d",nA + nB);
}

void minus(int nA, int nB)
{
printf("%d",nA - nB);
}

void multy(int nA, int nB)
{
printf("%d",nA * nB);
}

void divide(int nA, int nB)
{
printf("%d",nA / nB);
}


int main(int argc,char* argv[])
{
void (*ptrFunc[4])(int, int)={plus,minus,multy,divide};
printf("enter choice\n");
char choice;
scanf("%c",&choice);

int num;
int numb;

scanf("%d",&num);
scanf("%d",&numb);

//switch(*argv[2])
//{
puts("result is : ");
switch(choice){
    case '+': ptrFunc[0](num,numb);       break;
    case '-': ptrFunc[1](num,numb);       break;
    case '*': ptrFunc[2](num,numb);       break;
    case '/': ptrFunc[3](num,numb);       break;
    default:puts("invalid");
}
//printf(" %d ",ptrFunc(atoi(argv[1]),atoi(argv[3])));

return 0;
}
