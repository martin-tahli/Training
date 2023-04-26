
//. Напишете програма, която да изчислява средния успех на всеки
//студент и целия курс, използвайки структури. Входните данни за студентите
//трябва да бъдат въведени от потребителя. Принтирайте резултатите за
//всеки студент поотделно, както и за целия курс.

#include <stdio.h>

struct Student
{
    char name[10];
    double average;
    int math;
    int history;
    int geography;

};

void print(struct Student* student)
{
    printf("Student's Name: %s\n",student->name);
    printf("Student's Average: %.3f\n",student->average);
    printf("Student's math: %d\n",student->math);
    printf("Student's history: %d\n",student->history);
    printf("Student's geography: %d\n",student->geography);
}
void input(struct Student* student)
{
    puts("Students Name ?");
    scanf("%s",&student->name);
    puts("Students grade for Math ?");
    scanf("%d",&student->math);
    puts("Students grade for History ?");
    scanf("%d",&student->history);
    puts("Students grade for geography?");
    scanf("%d",&student->geography);
    puts("\n");
}
double average(struct Student*student,struct Student*student2)
{
    student->average=(student->geography+student->history+student->math)/3;
    student2->average=(student2->geography+student2->history+student2->math)/3;
}
int main()
{
struct Student s1,s2;

input(&s1);
input(&s2);

average(&s1,&s2);

print(&s1);
print(&s2);


return 0;
}
