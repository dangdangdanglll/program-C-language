#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
	char cName[20];
	int iNumber;
	struct Student *next;
	
};
int iCount;
struct Student *Create()
{
	 struct Student *pHead=NULL;
	 struct Student *pEnd,*pNew;
	 iCount=0;
	 pEnd=pNew=(struct Student *)malloc(sizeof(struct Student));
	 printf("请输入学生的姓名和学号：\n");
	 scanf("%s",pNew->cName);
	 scanf("%d",&pNew->iNumber);
	 while(pNew->iNumber!=0)
	 {
	 	iCount++;
	 	if(iCount==1)
	 	{
	 		pNew->next=pHead;
	 		pEnd=pNew;
	 		pHead=pNew;
		}
		else
		{
			pNew->next=NULL;
			pEnd->next=pNew;
			pEnd=pNew;
			
		}
		pNew=(struct Student *)malloc(sizeof(struct Student));
		scanf("%s",pNew->cName);
		scanf("%d",&pNew->iNumber);
	}
	 free(pNew);
	 return pHead;
}
void print(struct Student *pHead)
{
	struct Student *pTemp;
	int iIndex=1;
	printf("**********本名单中有%d个学生：**********\n",iCount);
	pTemp=pHead;
	while(pTemp!=NULL)
	{
		printf("第%d个学生是：\n",iIndex);
		printf("姓名：%s\n",pTemp->cName);
		printf("学号：%d\n\n",pTemp->iNumber);
		pTemp=pTemp->next;
		iIndex++;
	}
}
struct Student  *add(struct Student *pHead)
{
	struct Student *pTemp;
	pTemp=(struct Student *)malloc(sizeof(struct Student));
	printf("请输入姓名："); 
	scanf("%s",pTemp->cName);
	printf("请输入电话："); 
	scanf("%d",&pTemp->iNumber);
	pTemp->next=pHead;
    pHead=pTemp;
    iCount++;
	return pHead;
	
}
void query(struct Student *pHead)
{
	char s[10]; 
	struct Student *pTemp;
	pTemp=pHead;
	printf("请输入查询的姓名：");
	scanf("%s",s); 
	while(pTemp!=NULL)
	{
		if(!(strcmp(s,pTemp->cName)))
		{
			printf("电话号码是：%d\n",pTemp->iNumber);
			break;
		}
		
		else
		pTemp=pTemp->next;
	 } 
}
void deletee(struct Student *pHead)
{
	int i,nu;
	printf("请输入第几要删除的人");
	scanf("%d",&nu); 
	struct Student *pTemp,*pPre;
	pTemp=pHead;
	pPre=pTemp;
	for(i=1;i<nu;i++)
	{
		pPre=pTemp;
		pTemp=pTemp->next;
		
	}
	pPre->next=pTemp->next;
	free(pTemp);
	iCount--; 
	 
}
main()
{
	struct Student *pHead;
	pHead=Create();
	print(pHead);
	query(pHead);
	pHead=add(pHead);
	print(pHead);
	deletee(pHead);
	print(pHead);
}

