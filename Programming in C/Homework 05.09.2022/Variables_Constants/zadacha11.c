/*Задача 11. Ако имаме символен низ от символа char str[] =
“Hello”; копирайте всеки един от неговите символи в низ, който
да изглежда огледален на него. Ето така char rts[] = “ollеH”; и
принтирайте резултата.*/



#include<stdio.h>
#include<string.h>
char * strrev1(char a[])
{
	int i, j;
	char temp;

	for (i=0, j=strlen(a)-1 ; i<j ; i++, j--) {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	return a;
}

int main()
{
   char str[] = "Hello";

   printf("The given string is = %s\n",str);

   printf("After reversing string is = %s",strrev1(str));

   return 0;
}
