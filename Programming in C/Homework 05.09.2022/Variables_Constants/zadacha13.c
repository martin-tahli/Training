/*Задача 13. Ако имаме символен низ char str[] = “HELLO”, заменете
всичките символи с главна буква със съответните символи с
малка буква.*/

#include <stdio.h>
#include <string.h>

int main()
{
  	char str[] = "Hello";
  	int i;


  	for (i = 0; str[i]!='\0'; i++)
  	{
  		if(str[i] >= 'A' && str[i] <= 'Z')
  		{
  			str[i] = str[i] + 32;
		}
  	}

  	printf("\n  %s\n", str);

  	return 0;
}
