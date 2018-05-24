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
{//�ϲ�����La��Lb���ϲ�����±�ʹ��ͷָ��Lcָ��  
  Linklist pa,pb,pc,q;
  pa=La->next;  pb=Lb->next;   
  //pa��pb�ֱ�������La��Lb�Ĺ���ָ��,��ʼ��Ϊ��Ӧ����ĵ�һ�����  
  Lc=pc=La; //��La��ͷ�����ΪLc��ͷ���   
  Lc->next=NULL;  
  while(pa||pb )  
{//ֻҪ����һ���ǿձ���qָ���ժȡ��Ԫ��  
    if(!pa)  {  
    q=pb;  
    pb=pb->next;  
    }  
//La��Ϊ�գ���qָ��pb��pbָ�����  
    else if(!pb)  {  
    q=pa;    
    pa=pa->next;  
    }   
//Lb��Ϊ�գ���qָ��pa��paָ�����  
    else if(pa->data<=pb->data)  {  
    q=pa;    
    pa=pa->next;  
    }  
//ȡ��С�ߣ�������ȣ�La�е�Ԫ�أ���qָ��pa��paָ�����  
    else {  
    q=pb;    
    pb=pb->next;  
    }  
//ȡ��С��Lb�е�Ԫ�أ���qָ��pb��pbָ�����  
     q->next = Lc->next;   
      Lc->next = q;     
//��qָ��Ľ�����Lc ��ı�ͷ���֮��  
    }  
    free(Lb);             //�ͷ�Lb��ͷ���  
}
  

    
  
  
int  main()  
{  
    Linklist A,B,t;  
    printf("�������һ������[���븺������]\n");
    creatlist(A); 
    printf("������ڶ�������[���븺������]\n"); 
    creatlist(B);  
    MergeList(A,B,t);  
    printf("�ϲ��������Ϊ��\n"); 
    print(t);  
    return 0;  
} 
