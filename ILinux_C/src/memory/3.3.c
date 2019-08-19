#include<malloc.h>
#include<stdio.h>
#define LEN sizeof(struct student)
typedef struct student {
	int num;
	int age;
	float score;
	struct student *next;/*指向链表的下一个结点*/
} stu; /*声明结构体类型struct student，并取别名为stu*/
int n;
stu *creat(void) /*创建动态链表函数*/
{
	stu *head, *p1, *p2; /*定义结构体类型的指针*/
	n = 0;
	p1 = p2 = (stu *) malloc(LEN);/*开辟一个内存空间*/
	scanf("%d,%d,%f", &p1->num, &p1->age, &p1->score);/*输入结构体类型的数据*/
	head = NULL; /*头指针置空*/
	while (p1->num != 0) /*判断学号输入是否为0，若是0则跳出循环*/
	{
		n = n + 1;
		if (n == 1)
			head = p1; /*判断是否是输入的第1个数据信息，若是第一个数据信息，则将头指针指向p1*/
		else
			p2->next = p1; /*将p2指向的下一个地址指向p1*/
		p2 = p1; /*p2指向p1*/
		p1 = (stu *) malloc(LEN);/*再次为p1开辟一个内存空间，存储下一个数据*/
		scanf("%d,%d,%f", &p1->num, &p1->age, &p1->score);
	}
	p2->next = NULL; /*p2指向下一个地址指向的是空指针*/
	return (head); /*返回数据信息的头指针，以便从头输出*/
}
main() {
	stu *p, *head;
	head = creat();
	p = head; /*p指向头指针*/
	if (head != NULL) /*判断头指针是否为空，不为空则执行循环体输出信息*/
		do {
			printf("%d,%d,%f\n", p->num, p->age, p->score);
			p = p->next;
		} while (p != NULL);
}
