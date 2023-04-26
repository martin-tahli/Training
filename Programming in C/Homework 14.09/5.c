// Напишете програма на С, която чрез функция проверява дали
//дадено число е четно или не.

#include <stdio.h>

int chetno(int a)
{
if(a%2==0)printf("Chetno");
else printf("nechetno");

}



int main(){

chetno (4);

return 0;
}
