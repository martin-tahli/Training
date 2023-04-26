//Напишете макрос с променлив брой параметри, който
//извиква printf със префикс “TRACE: ”
//

#include <stdio.h>
#define VAR_PARAM(args, ...) printf(args ,##args);


int main(){

VAR_PARAM(%d,5)

return 0;
}
