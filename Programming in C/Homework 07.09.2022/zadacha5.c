/*5. Да се намери сумата от тези елементи на редица, които са удвоени нечетни числа, ако:
а/редицата е с 41 елемента;
б/първо се въвежда броят на елементите на редицата;
в/редицата е последен елемент 0;
г/редицата е с елементи, чиято сума е по-голяма от 999.*/



#include <stdio.h>

int main() {
int n,i, sum=0,variable;

printf("Enter N: \n");
scanf("%d", &n);


for(i = 1; i < 42; i++) {
variable = i / 2;
if(variable % 2 != 0 && variable * 2 == i) {
sum += i;
}
}

printf("The first sum is: %d \n", sum);

sum = 0;
for(i = 1; i <= n; i++) {
variable = i / 2;
if(variable % 2 != 0 && variable * 2 == i) {
sum += i;
}
}

printf(" N number's sum is: %d \n", sum);

sum = 0;


for(i = 85; i >= 0; i--) {
variable = i / 2;
if(variable % 2 != 0 && variable * 2 == i) {
sum += i;
}
}

printf("when number 0 is the last : %d \n", sum);

sum = 0;

for(i = 1; sum < 1000; i++) {
variable = i / 2;
if(variable % 2 != 0 && variable * 2 == i) {
sum += i;
}
}
printf("The higher sum than 999 is : %d \n", sum);

return 0;
}
