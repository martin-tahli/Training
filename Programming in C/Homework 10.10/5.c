
//Напишете макрос с един параметър, който печата
//съобщение, само при дефиниран макрос DEBUG. Ако DEBUG не е
//дефиниран, не печата нищо.



#include <stdio.h>
#define DEBUG printf("DEBUG is defined now\n");
#ifdef DEBUG

    #define PRINT(X) printf("Value of x is: %d,and adress is %p",X,&X);
#endif // DEBUG


int main(){
int a =199;

PRINT(a);

return 0;
}
