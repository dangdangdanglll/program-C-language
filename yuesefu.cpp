#include<stdio.h>
#include<stdlib.h> 
struct yue
{
	int number;
	struct yue *next;
};
struct yue *create()
{
	int i;
	struct yue *phead,*pend,*pnew;
	pend=pnew=(struct yue *)malloc(sizeof(struct yue));
	pnew->number=1;
	phead=pnew;
	for(i=1;i<9;i++)
	{
		pnew=(struct yue *)malloc(sizeof(struct yue));
	    pnew->number=i+1;
	    pend->next=pnew;
	    pend=pnew;
	}
	pend->next=NULL;
	return phead;
}
void print(struct yue *pHead)
{
	struct yue *pTemp;
	pTemp=pHead;
	while(pTemp->next!=NULL)
	{
		printf("����Ϊ��%d\n",pTemp->number);
		pTemp=pTemp->next;
	}
}
void yuesefu(struct yue *phead)
{
	struct yue *stu1,*stu2;
	stu1=stu2=phead;
	int i;
	for(i=1;i<=3;i++)
	{
		stu1=stu1->next;
	}
	stu2=(stu1->next)->next;
	stu1->next=stu2;
	
}

	
 


int main()
{
	struct yue *stu;
	int m=4,n=9;
    stu=create();
    printf("ԭ����Ϊ��"); 
    print(stu);
    yuesefu(stu);
    printf("��һ�α仯��\n\n");
    print(stu);
    printf("�ڶ��α仯��\n\n");
    yuesefu(stu);
    print(stu);
    printf("�����α仯��\n\n");
    yuesefu(stu);
    print(stu);
    printf("���Ĵα仯��\n\n");
    yuesefu(stu);
    print(stu);
    printf("����α仯��\n\n");
    yuesefu(stu);
    print(stu);
	return 0;
}

