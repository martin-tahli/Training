//Използвайте do-while цикъл, за да напишете функцията void
//itoa(int n, char s[ ]), която преобразува число в символен низ (обратната
//функция на atoi)

#include <stdio.h>

int numLength (int n) {

    int length = 0;

    for (int i = 0; n; i++)
    {
        n /= 10;
        length++;
    }
    return length;
}

void itoa(int n, char s[]) {
    int nLength = numLength(n);
    *(s+nLength-1) = (n % 10) + '0'; // convert to char and put it in the right place
}

int main() {
    int num = 7018151;
    char str[60] = {};
    do
    {
        itoa(num, str);
        num /= 10; // remove last digit

    } while (num);

    printf("%s", str);

    return 0;
}
