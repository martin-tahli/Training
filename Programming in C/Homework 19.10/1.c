//. Дефинирайте структура като потребителски тип.Инициализирайте
//членовете на структурата, използвайки новия потребителски тип. Отпечатайте

#include <stdio.h>

typedef struct User
{
    int ID;
    char *name;

}User;

int main()
{

User u1;

u1.ID=65;
u1.name="Ivan";

printf("%d \n",u1.ID );
printf("%s ",u1.name );

return 0;

}
