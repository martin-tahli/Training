//
//Напишете функция int getline(char s[],int lenght),
//която чете ред в s[] и връща дължината му

#include <stdio.h>
#include <string.h>

int get_line(char s[], int lenght) {
    int static count = 0;
    if(*s == '\n') {
        return count;
    }
    else if(count == lenght) {
        return lenght;
    }
    count++;
    get_line(s+1, lenght);
}

int main() {
    char str[] = {"input a string"};

    int lenght = strlen(str);
    int result = get_line(str, lenght);
    printf("%d", result);

    return 0;
}
