#include<stdio.h>  
#include<malloc.h>  
typedef struct LNode  
{  
    int data;  
    struct LNode *next;  
}LNode,*Linklist;  
  
  
void creatlist(Linklist &l)  
{  
    Linklist p,q;  
    l=(Linklist)malloc(sizeof(LNode));  
    l->next=NULL;  
  
    p=l;  
  
    while(1)  
    {  
        q=(Linklist)malloc(sizeof(LNode));  
        q->next=NULL;  
        scanf("%d",&q->data);  
        if(q->data<0)  
            break;  
  
        p->next=q;  
        p=q;  
    }  
  
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

void MergeList(Linklist &La, Linklist &Lb, Linklist &Lc )   
{//合并链表La和Lb，合并后的新表使用头指针Lc指向  
  Linklist pa,pb,pc,q;
  pa=La->next;  pb=Lb->next;   
  //pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点  
  Lc=pc=La; //用La的头结点作为Lc的头结点   
  Lc->next=NULL;  
  while(pa||pb )  
{//只要存在一个非空表，用q指向待摘取的元素  
    if(!pa)  {  
    q=pb;  
    pb=pb->next;  
    }  
//La表为空，用q指向pb，pb指针后移  
    else if(!pb)  {  
    q=pa;    
    pa=pa->next;  
    }   
//Lb表为空，用q指向pa，pa指针后移  
    else if(pa->data<=pb->data)  {  
    q=pa;    
    pa=pa->next;  
    }  
//取较小者（包括相等）La中的元素，用q指向pa，pa指针后移  
    else {  
    q=pb;    
    pb=pb->next;  
    }  
//取较小者Lb中的元素，用q指向pb，pb指针后移  
     q->next = Lc->next;   
      Lc->next = q;     
//将q指向的结点插在Lc 表的表头结点之后  
    }  
    free(Lb);             //释放Lb的头结点  
}
  

    
  
  
int  main()  
{  
    Linklist A,B,t;  
    printf("请输入第一个链表[输入负数结束]\n");
    creatlist(A); 
    printf("请输入第二个链表[输入负数结束]\n"); 
    creatlist(B);  
    MergeList(A,B,t);  
    printf("合并后的链表为：\n"); 
    print(t);  
    return 0;  
} 
