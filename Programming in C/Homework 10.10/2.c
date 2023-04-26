//
//Напишете макрос swap(t, x, y), койтo променя местата на двата
//аргумента от тип t.
#include <stdio.h>

#define t int
#define swap(t, x, y) x^=y;y^=x;x^=y; \
printf(" x=%d y=%d",x,y);

int main(){

int x =5;
int y=3;
//int t=0;

swap(t,x,y);


return 0;}
