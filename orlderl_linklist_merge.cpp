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

void merge1(Linklist &A,Linklist &B,Linklist &C)//������A��B�ϲ�ΪC,A��B��Ԫ�ؼ������,��ʹ��ԭ�洢�ռ�
{
  Linklist p,q,t,s;
  p=A->next;q=B->next;C=A;
  while(p&&q)
  {
    s=p->next;p->next=q; //��B��Ԫ�ز���
    if(s)
    {
      t=q->next;q->next=s; //��A�ǿ�,��A��Ԫ�ز���
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
    printf("����������1\n");
    creatlist(A); 
    printf("����������2��\n");
	creatlist(B); 
	merge1(A,B,a);
	printf("�������ǣ�\n");
	print(a);
    
    return 0;  
} 
