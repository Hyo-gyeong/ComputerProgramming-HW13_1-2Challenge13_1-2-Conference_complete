//20190975 컴퓨터학과 신효경
#include <stdio.h>
struct student{
	char name[20];
	int midterm;
	int final;
	int average;
};
typedef struct student Student;
struct cClass {
	int num;
	Student s[40];
};
typedef struct cClass CClass;

void printStudent(Student *sp)
{
	printf("%s\t", sp->name);
	printf("%d\t%d\t%d\n", sp->midterm, sp->final, sp->average);
}

void readStudentScore(Student *sp)
{
	printf("Enter student name: ");
	scanf("%s", sp->name);
	printf("Enter midtern and final score: ");
	scanf("%d %d", &sp->midterm, &sp->final);
}

void calculateStudentAverage(Student *sp)
{
	sp->average = (sp->midterm + sp->final) / 2;
}
int main(void)
{
	CClass c2;
	int i;

	printf("Enter a number of student: ");
	scanf("%d", &c2.num);

	for (i = 0; i < c2.num; i++)
		readStudentScore(&c2.s[i]);

	for (i = 0; i < c2.num; i++) 
		calculateStudentAverage(&c2.s[i]);

	printf("\n이름\t중간\t학기말\t평균\n");
	for (i = 0; i < c2.num; i++)
		printStudent(&c2.s[i]);
}