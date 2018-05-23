#include<stdio.h>
#include<stdlib.h>
struct linkedList
{
	int n;
	struct linkedList *next;
};
int iCount; 
struct linkedList *create()
{
	struct linkedList *pHead=NULL;
	struct linkedList *pEnd,*pNew;
	pEnd=pNew=(struct linkedList *)malloc(sizeof(struct linkedList));
	pNew->n=1;
	pHead=pNew;
	pEnd=pNew;
	pNew=(struct linkedList *)malloc(sizeof(struct linkedList));
	pNew->n=2;
	pEnd->next=pNew;
	pEnd=pNew;            
	pNew=(struct linkedList *)malloc(sizeof(struct linkedList));
	pNew->n=3;
	pEnd->next=pNew;
	pEnd=pNew;
	pNew=(struct linkedList *)malloc(sizeof(struct linkedList));
	pNew->n=4;
	pEnd->next=pNew;
	pEnd=pNew;
	pEnd->next=NULL;
	return pHead; 
}
void print(struct linkedList *pHead)   
{
	struct linkedList *pTemp;
	pTemp=pHead;
    printf("%d\n",pTemp->n);
	pTemp=pTemp->next; 
	printf("%d\n",pTemp->n);
	pTemp=pTemp->next;
	printf("%d\n",pTemp->n);
	pTemp=pTemp->next;
	printf("%d\n",pTemp->n); 
	
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
