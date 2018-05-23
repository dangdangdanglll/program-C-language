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
			printf("请输入第%d个节点：",iCount); 
			pEnd=pNew=(struct linkedList *)malloc(sizeof(struct linkedList));
			scanf("%d",&pNew->n);
			pHead=pNew;
			pEnd=pNew;
		}
		else
		{
			printf("请输入第%d个节点：",iCount); 
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
	printf("原链表为:\n");
	print(pHead);
	pHead=reverse(pHead);
    printf("新链表为:\n");
    print(pHead);
}
