#include<stdio.h>
#include<stdlib.h> 
struct yuesefu{
	int number;
	int passw;
	struct yuesefu *next;
};
struct yuesefu *create(int a)
{
	
	struct yuesefu *head=NULL;
	struct yuesefu *end,*nnew;
	int i,j=1;
	end=(struct yuesefu *)malloc(sizeof(struct yuesefu));
	scanf("%d",&end->passw);
	end->number=j;
	head=end;
	for(i=0;i<a-1;i++)
	{
		j++;
		nnew=(struct yuesefu *)malloc(sizeof(struct yuesefu));
		scanf("%d",&nnew->passw);
		nnew->number=j;
		end->next=nnew;
		end=nnew;
		
		
	}
	end->next=head; 
	return head;
}

int pro(struct yuesefu *a,int b,int c)
{
	struct yuesefu *poi,*temp;
	int i,j,k,m;
	poi=a;
	int password=b;
	int counter=c;
	int newpa;
	
	if(password==1)
	{
		for(m=0;m<counter-1;m++)
		  poi=poi->next;
		printf("%d ",poi->next->number);
	    newpa=poi->next->passw;
	    temp=poi->next->next;
	    free(poi->next);
	    poi->next=NULL;
	    poi->next=temp;
		for(j=0;j<c-1;j++)
	    {
		  for(k=0;k<newpa-1;k++)
		    poi=poi->next;
		  printf("%d ",poi->next->number);
	      newpa=poi->next->passw;
	      temp=poi->next->next;
	      free(poi->next);
	      poi->next=NULL;
	      poi->next=temp;
	    }	
		
	}
	else {
	
	for(i=0;i<password-2;i++)
	{
		poi=poi->next;
	}
	printf("%d ",poi->next->number);
	newpa=poi->next->passw;
	temp=poi->next->next;
	free(poi->next);
	poi->next=NULL;
	poi->next=temp;
	for(j=0;j<c-1;j++)
	{
		for(k=0;k<newpa-1;k++)
		  poi=poi->next;
		printf("%d ",poi->next->number);
	    newpa=poi->next->passw;
	    temp=poi->next->next;
	    free(poi->next);
	    poi->next=NULL;
	    poi->next=temp;
	}
	
    }
	return 0;
}
int main()
{
	int counter,password;
	struct yuesefu *head;
	scanf("%d %d",&counter,&password);
	head=create(counter);
	pro(head,password,counter);
	
	
}
