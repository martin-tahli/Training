/*Упражнение 18* Направете бягаща светлина, като приемете, че всеки бит от
дадена променлива, е свързан с лампа (или светодиод). Когато битът е
нула, лампата не свети, когато е единица свети.
Примерно, ако генерирате последователност:
1, 2, 3, 4, се получава следното:
1 *....................
2 .*...................
4 ..*..................
8 ...*................. ...
За да генерирате закъснение, използвайте следната функция от C runtime:
*/

#include <unistd.h>
unsigned int sleep(unsigned int seconds);


#include <stdio.h>
#include <unistd.h>

void print(char* lights, int position) {
	lights[position - 1] = '*';
	printf("%s\n", lights);
	sleep(1);
	lights[position - 1] = '.';
}

int main() {

	char lights[] = "..........";


for(int i=0;i<=10;i++)
{
	print(lights, i);
    if(i==10)
    {
        for( i;i>0;i--)
        {
            print(lights, i);
        }
    }
}

	return 0;
}
