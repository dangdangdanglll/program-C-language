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
		printf("请输入第%d个姓名和电话：",i+1); 
		scanf("%s",stu[i].name);
		scanf("%s",stu[i].number);
	}
	return 0;
}
int output()
{
	int i;
	printf("通讯录是：\n");
	for(i=0;i<N;i++)
	{
		printf("第%d个联系人的姓名和电话是：",i+1); 
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
	printf("请输入要查找的联系人的姓名："); 
	scanf("%s",na);
	for(i=0;i<N;i++)
	{
		if(!(strcmp(na,stu[i].name)))
		{
		printf("要查找联系人的电话为：");
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
	printf("请输入要添加的联系人的姓名和电话："); 
	scanf("%s",na);
	scanf("%s",nu);
	for(i=0;i<N;i++)
	{
		if(!(strcmp(na,stu[i].name)))
		strcpy(stu[i].number2,nu);
	}
	printf("新通讯录是：\n");
	for(i=0;i<N;i++)
	{
		printf("第%d个联系人的姓名和电话是：\n",i+1); 
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
	printf("请输入要删除电话的联系人姓名：");
	scanf("%s",na);
	for(i=0;i<N;i++)
	{
		if(!(strcmp(na,stu[i].name)))
		strcpy(stu[i].number," ");
	}
	printf("新通讯录是：\n");
	for(i=0;i<N;i++)
	{
		printf("第%d个联系人的姓名和电话是：",i+1); 
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

