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

void merge1(Linklist &A,Linklist &B,Linklist &C)//把链表A和B合并为C,A和B的元素间隔排列,且使用原存储空间
{
  Linklist p,q,t,s;
  p=A->next;q=B->next;C=A;
  while(p&&q)
  {
    s=p->next;p->next=q; //将B的元素插入
    if(s)
    {
      t=q->next;q->next=s; //如A非空,将A的元素插入
    }
    p=s;q=t;
  }//while
}//merge1
  
void print(Linklist l)  
{  
    Linklist p;  
    p=l->next;  
//    printf("jjj");
    while(p)  
    {  
      printf("%d ",p->data);  
 //     printf("kk");
      p=p->next;  
    } 
//	printf("lll"); 
}    
int  main()  
{  
    int i1,i2;
    Linklist A,B,a;  
    printf("请输入链表1\n");
    creatlist(A); 
    printf("请输入链表2：\n");
	creatlist(B); 
	merge1(A,B,a);
	printf("新链表是：\n");
	print(a);
    
    return 0;  
} 
