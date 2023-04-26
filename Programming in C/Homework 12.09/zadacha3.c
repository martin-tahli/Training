/*3.Напишете програма, която преброява шпациите, табулациите и
новите редове.
*/

#include <stdio.h>


int main(){
int space=0,tab=0,rows=0;
char c;


while(getchar()!=EOF){


for (c = getchar(); c != EOF; c = getchar()){
        if (c == '\n'){rows +=  1;}
        if (c == ' '){space +=  1;}
        if (c == '\t'){tab +=  1;}


}
}
printf("Spaces: %d  Tabs: %d  Rows: %d  ",space,tab,rows);



return 0;
}
