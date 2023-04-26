
//Реализирайте условна компилация в зависимост от макрос DEBUG

#include <stdio.h>
#define DEBUG printf("DEBUG is defined now\n");



int main(int argc, char **argv){


if(argv!=EOF) DEBUG;

return 0;
}
