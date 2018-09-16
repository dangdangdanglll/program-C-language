#include<stdio.h>
#include<stdlib.h>
struct duoxs{
	char l,c,r;
	int constant;
	int index;                               
	struct duoxs *next;
}; 

struct duoxs *create(int a)
{
	int j=a-1;
	struct duoxs *head=NULL;
	struct duoxs *end,*nnew;
	end=(struct duoxs *)malloc(sizeof(struct duoxs));
	scanf("%c%d%c%d%c",&end->l,&end->constant,&end->c,&end->index,&end->r);
	head=end; 
	for(int i=0;i<j+1;i++)
	{
		nnew=(struct duoxs *)malloc(sizeof(struct duoxs));
		scanf("%c%d%c%d%c",&nnew->l,&nnew->constant,&nnew->c,&nnew->index,&nnew->r);
		end->next=nnew;
		end=nnew;
	}
//	end->next=NULL;
	return head;
}

int pro(struct duoxs *a,int c)
{
	struct duoxs *poi;
	poi=a->next;
	if(poi->index==0)
	{
		printf("%d",poi->constant);
	}
	else if(poi->index==1)
	{
		if(poi->constant==1)
		  printf("X");
		else
		  printf("%dX",poi->constant);
	}
	else
	{
		if(poi->constant==1)
		  printf("X^%d",poi->index);
		else
		  printf("%dX^%d",poi->constant,poi->index);
	}
	poi=poi->next;
	for(int i=0;i<c;i++)
	{
		if(poi->constant<0)
		  printf("%dX^%d",poi->constant,poi->index);
		else
		  printf("+%dX^%d",poi->constant,poi->index);
		poi=poi->next;
	}
}
int main()
{
	struct duoxs *head;
	int counter;
	scanf("%d",&counter);
	head=create(counter);
	pro(head,counter);
	return 0;
	
}
