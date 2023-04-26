//
//Напишете програма, която да намери броя на гласни и съгласни букви в
//текст, въведен от клавиатурата, като използвате указатели.

#include <stdio.h>

int main()
{
char s[1000];
    int i,vowels=0,consonants=0;


    printf("input here: ");
    gets(s);
char *p=s;

    for(i=0;*(p+i);i++)
    {
    	if((*(p+i)>=65 && *(p+i)<=90)|| (*(p+i)>=97 && *(p+i)<=122))
    	{

            if(*(p+i)=='a'|| *(p+i)=='e'||*(p+i)=='i'||*(p+i)=='o'||*(p+i)=='u'||*(p+i)=='A'||*(p+i)=='E'||*(p+i)=='I'||*(p+i)=='O' ||*(p+i)=='U')
		      vowels++;
            else
             consonants++;
        }

 	}


    printf("vowels = %d\n",vowels);
    printf("consonants = %d\n",consonants);



return 0;}
