//20190975 ��ǻ���а� ��ȿ��
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
int main(void)
{
	CClass c2;
	int i;
	Student all = {"Tom", 0, 0, 0};

	printf("Enter a number of student: ");
	scanf("%d", &c2.num);

	readClass(&c2);

	calculateClassAverage(&c2);
	
	printf("\n�̸�\t�߰�\t�б⸻\t���\n");
	printfClass(&c2);
}