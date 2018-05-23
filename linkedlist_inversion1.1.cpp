#include<stdio.h>
#include<stdlib.h>
struct linkedList
{
	int n;
	struct linkedList *next;
};
int iCount=0; 
struct linkedList *create()
{
	struct linkedList *pHead=NULL;
	struct linkedList *pEnd,*pNew;
	while(pNew->n!=0) 
	{
		iCount++;
		if(iCount==1) 
		{
			printf("�������%d���ڵ㣺",iCount); 
			pEnd=pNew=(struct linkedList *)malloc(sizeof(struct linkedList));
			scanf("%d",&pNew->n);
			pHead=pNew;
			pEnd=pNew;
		}
		else
		{
			printf("�������%d���ڵ㣺",iCount); 
			pNew=(struct linkedList *)malloc(sizeof(struct linkedList));
			scanf("%d",&pNew->n);
			pEnd->next=pNew;
			pEnd=pNew;
		}
	}
	pEnd->next=NULL;
	return pHead; 
}
void print(struct linkedList *pHead)   
{
	struct linkedList *pTemp;
	pTemp=pHead;
	while(pTemp!=NULL) {
      printf("%d\n",pTemp->n);
	  pTemp=pTemp->next; 
    }
}
struct linkedList *reverse(struct linkedList *pHead)
{
    if(pHead == NULL||pHead->next == NULL)
		return pHead;
	struct linkedList *pRev=NULL;
	struct linkedList *pCur = pHead;
	while(pCur!=NULL)
	{
		struct linkedList *pTemp = pCur;
		pCur = pCur->next;
		pTemp->next = pRev;
		pRev = pTemp;
	}
	return pRev;
}
 main()
{
	struct linkedList *pHead;
	pHead=create();
	printf("ԭ����Ϊ:\n");
	print(pHead);
	pHead=reverse(pHead);
    printf("������Ϊ:\n");
    print(pHead);
}
