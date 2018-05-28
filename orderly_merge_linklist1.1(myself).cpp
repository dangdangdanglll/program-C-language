#include<stdio.h>  
#include<malloc.h>  
typedef struct LNode  
{  
    int data;  
    struct LNode *next;  
}LNode,*Linklist;  
  
int iCount=0;
int creatlist(Linklist &l) 
{  
    Linklist p,q;  
    l=(Linklist)malloc(sizeof(LNode));  
    l->next=NULL;  
  
    p=l;  
  
    while(1)  
    {  
        iCount++;
        q=(Linklist)malloc(sizeof(LNode));  
        q->next=NULL;  
        scanf("%d",&q->data);  
        if(q->data<0)  
            break;  
  
        p->next=q;  
        p=q;  
    } 
    return iCount;
    
  
}  

LNode *merge2(Linklist &a,int l1,Linklist &b,int l2)
{
	Linklist pa,pb,phead;
	pa=a->next;
	pb=b->next;
	printf("geshus%d  %d\n",l1,l2);
	if(l2<l1)
	{ 
		phead=b;
		while(pb->next)
		{
			a=pa;
			b=pb;
			pa=pa->next;
			pb=pb->next;
			a->next=pb;
			b->next=a;
		}
		pb->next=pa;
		free(a);
	}
	else
	{
		phead=a;
		while(pa->next)
		{
			a=pa;
			b=pb;
			pa=pa->next;
			pb=pb->next;
			b->next=pa;
			a->next=b;
			
		}
		pa->next=pb;
	}
	return phead;
}
  
void print(Linklist l)  
{  
    Linklist p;  
    p=l->next;  
    while(p)  
    {  
      printf("%d ",p->data);  
      p=p->next;  
    } 
}    
int  main()  
{  
    int i1,i2;
    Linklist A,B,t;  
    printf("请输入链表1\n");
    i1=creatlist(A); 
    iCount=0;
    printf("请输入链表2：\n");
	i2=creatlist(B); 
	t=merge2(A,i1,B,i2);
	printf("新链表是：\n");
	print(t);
    
    return 0;  
} 
