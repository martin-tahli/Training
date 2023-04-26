//Задача 1.  Напишете програма, която чете съобщение от няколко думи и го принтира в обратен ред.
//
//Задача 2.  Пренапишете горния код като работите с аритметика с указатели.
//


#include <stdio.h>

int main(int argc, char *argv[])
{


    for (int i=argc-1;i>0;--i)
    {
        printf(" %s",argv[i]);

    }
    printf("\n");



    argv = argv + argc-1;
    for(int i = argc-1 ;i>0;argv--,i--)
    {
        if(*argv == argv[argc])
            {break;}
        printf("%s ",*argv);
    }
    printf("\n");




return 0;
}
