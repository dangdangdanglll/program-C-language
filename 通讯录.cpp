#include<stdio.h>
#include<string.h>
#define N  4
struct phone_book
{
	char name[20];
	char number[12];
	char number2[12];
}stu[N];
int input()
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("�������%d�������͵绰��",i+1); 
		scanf("%s",stu[i].name);
		scanf("%s",stu[i].number);
	}
	return 0;
}
int output()
{
	int i;
	printf("ͨѶ¼�ǣ�\n");
	for(i=0;i<N;i++)
	{
		printf("��%d����ϵ�˵������͵绰�ǣ�",i+1); 
		printf("%s ",stu[i].name);
		printf("%s ",stu[i].number);
		printf("%s\n",stu[i].number2);
	}
	return 0;
}
int find()
{
	int i,fl=0;
	char na[12];
	printf("������Ҫ���ҵ���ϵ�˵�������"); 
	scanf("%s",na);
	for(i=0;i<N;i++)
	{
		if(!(strcmp(na,stu[i].name)))
		{
		printf("Ҫ������ϵ�˵ĵ绰Ϊ��");
		printf("%s\n",stu[i].number);
		fl=1;
	    }
	}
	    if(fl==0)
	    printf("not this name!");
	
}
int addnew()
{
	int i;
	char na[20];
	char nu[12];
	printf("������Ҫ��ӵ���ϵ�˵������͵绰��"); 
	scanf("%s",na);
	scanf("%s",nu);
	for(i=0;i<N;i++)
	{
		if(!(strcmp(na,stu[i].name)))
		strcpy(stu[i].number2,nu);
	}
	printf("��ͨѶ¼�ǣ�\n");
	for(i=0;i<N;i++)
	{
		printf("��%d����ϵ�˵������͵绰�ǣ�\n",i+1); 
		printf("%s ",stu[i].name);
		printf("%s ",stu[i].number);
		printf("%s\n",stu[i].number2);
	}
	return 0;
}
int delet()
{
	int i;
	char na[20];
	printf("������Ҫɾ���绰����ϵ��������");
	scanf("%s",na);
	for(i=0;i<N;i++)
	{
		if(!(strcmp(na,stu[i].name)))
		strcpy(stu[i].number," ");
	}
	printf("��ͨѶ¼�ǣ�\n");
	for(i=0;i<N;i++)
	{
		printf("��%d����ϵ�˵������͵绰�ǣ�",i+1); 
		printf("%s ",stu[i].name);
		printf("%s ",stu[i].number);
		printf("%s\n",stu[i].number2);
	}
}

int main()
{
	struct phone_book stu[N];
	input();
	output();
	find(); 
	addnew();
	delet();
    return 0;
}

