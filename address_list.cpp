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
	 printf("������ѧ����������ѧ�ţ�\n");
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
	printf("**********����������%d��ѧ����**********\n",iCount);
	pTemp=pHead;
	while(pTemp!=NULL)
	{
		printf("��%d��ѧ���ǣ�\n",iIndex);
		printf("������%s\n",pTemp->cName);
		printf("ѧ�ţ�%d\n\n",pTemp->iNumber);
		pTemp=pTemp->next;
		iIndex++;
	}
}
struct Student  *add(struct Student *pHead)
{
	struct Student *pTemp;
	pTemp=(struct Student *)malloc(sizeof(struct Student));
	printf("������������"); 
	scanf("%s",pTemp->cName);
	printf("������绰��"); 
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
	printf("�������ѯ��������");
	scanf("%s",s); 
	while(pTemp!=NULL)
	{
		if(!(strcmp(s,pTemp->cName)))
		{
			printf("�绰�����ǣ�%d\n",pTemp->iNumber);
			break;
		}
		
		else
		pTemp=pTemp->next;
	 } 
}
void deletee(struct Student *pHead)
{
	int i,nu;
	printf("������ڼ�Ҫɾ������");
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

