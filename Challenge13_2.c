//20190975 컴퓨터학과 신효경
#include <stdio.h>
#include <string.h>
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

void printfClass(CClass *cp)
{
	int i;

	for (i = 0; i < cp->num; i++) {
		printf("%s\t", cp->s[i].name);
		printf("%d\t%d\t%d\n", cp->s[i].midterm, cp->s[i].final, cp->s[i].average);
	}
}

void readClass(CClass *cp)
{
	int i;

	for (i = 0; i < cp->num; i++) {
		printf("Enter student name: ");
		scanf("%s", cp->s[i].name);
		printf("Enter midtern and final score: ");
		scanf("%d %d", &cp->s[i].midterm, &cp->s[i].final);
	}
}

void calculateClassAverage(CClass *cp)
{
	int i;

	for (i = 0; i < cp->num; i++) 
		cp->s[i].average = (cp->s[i].midterm + cp->s[i].final) / 2;
}

Student calculateAll2(CClass *cp) 
{
	Student pAll = {"All", 0, 0, 0};
	int i;

	for (i = 0; i < cp->num; i++) {
		pAll.midterm += cp->s[i].midterm;
		pAll.final += cp->s[i].final;
		pAll.average += cp->s[i].average;
	}
	pAll.midterm /= cp->num;
	pAll.final /= cp->num;
	pAll.average /= cp->num;

	return pAll;
}

void printStudent(Student *all)
{
	printf("%s\t%d\t%d\t%d\n",all->name, all->midterm, all->final, all->average);
}
int main(void)
{
	CClass c2;
	
	Student all = {"All", 0, 0, 0};

	printf("Enter a number of student: ");
	scanf("%d", &c2.num);

	readClass(&c2);

	calculateClassAverage(&c2);
	
	printf("\n이름\t중간\t학기말\t평균\n");
	printfClass(&c2);

	all = calculateAll2(&c2);
	printf("------------------------------\n");
	printStudent(&all);
}