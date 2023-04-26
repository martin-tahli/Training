
//Напишете програма, която калкулира разликата на два времеви
//периода, изразени във векове, години, месеци, дни, минути, секудни.
//Принтирайте изходните периоди и резултата.

#include<stdio.h>

struct Time
{

    int year;
    int month;
    int day;
    int minute;
    int seconds;
};

void input(struct Time* time1);

void print(struct Time*result);

int timeCalc(struct Time*time1,struct Time*time2,struct Time* result);

int main(){
struct Time time1,time2,result;
input(&time1);
input(&time2);

timeCalc(&time1,&time2,&result);

print(&time1);
print(&time2);

print(&result);

return 0;
}
void input(struct Time* time1)
{

    printf("which year? ");
    scanf("%d",&time1->year);
    printf("which month? ");
    scanf("%d",&time1->month);
    printf("which day? ");
    scanf("%d",&time1->day);
    printf("which minute? ");
    scanf("%d",&time1->minute);
    printf("which second? ");
    scanf("%d",&time1->seconds);
}
void print(struct Time*result)
{

    printf("time Difference in years %d\n",     result->year);
    printf("time Difference in months %d\n",    result->month);
    printf("time Difference in days %d\n",      result->day);
    printf("time Difference in minutes %d \n",   result->minute);
    printf("time Difference in seconds %d \n",   result->seconds);
}
int timeCalc(struct Time* time1,struct Time* time2, struct Time* result)
{
     if (time1->year>time2->year)
     {
        result->year    =   time1->year        -   time2->year;
        result->month   =   time1->month       -   time2->month;
        result->day     =   time1->day      -   time2->day;
        result->minute  =   time1->minute   -   time2->minute;
        result->seconds =   time1->seconds  -   time2->seconds;
        while(result->month>12){result->month-=12;result->year+=1;}
        while(result->day>30){result->day-=30;result->month+=1;}
        while(result->minute>1440){result->minute-=1440;result->day+=1;}
        while(result->seconds>60){result->seconds-=60;result->minute+=1;}

    }
    else
    {
        result->year    =   time2->year        -   time1->year;
        result->month   =   time2->month    -   time1->month;
        result->day     =   time2->day      -   time1->day;
        result->minute  =   time2->minute   -   time1->minute;
        result->seconds =   time2->seconds  -   time1->seconds;
        while(result->month<0){result->month+=12;result->year-=1;}
        while(result->day<0){result->day+=30;result->month-=1;}
        while(result->minute<0){result->minute+=1440;result->day-=1;}
        while(result->seconds<0){result->seconds+=60;result->minute-=1;}
    }

}
