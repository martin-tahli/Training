/*4. Дадени са a, b, N (b !=0, 1<=N<=100). Да се намери частното a/b и да се отпечата на екрана с N цифри след десетичната запетая.*/

#include <stdio.h>

int main() {
	double a, b;
	int n;
	printf("enter a,b,n");

    scanf("%f %f %d", &a, &b, &n);
	double result = a / b;

	printf("%.*f", n, result);

	return 0;
}
