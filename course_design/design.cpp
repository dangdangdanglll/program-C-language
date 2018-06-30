#include<stdio.h>           //能写入文件 ,可排序 
#include<string.h>           //问题：只执行创建链表函数存在bug(头节点) 
#include<stdlib.h>          //       第一次登陆错误，第二次登陆正确时选项bug 
#include<conio.h>
int root=0;
float avescore=0,averebound=0;
struct nba                      //正代 
{
	char name[20];
	int score; 
	float rebound;  
	int fl;                                                     //******
	struct nba *next; 
}stu; 
int counter=0;
struct nba *create()                         //创建链表函数 
{
	struct nba *head=NULL;
	struct nba *nnew,*end;
	end=(struct nba *)malloc(sizeof(struct nba));
//	printf("请输入球员姓名：");
//	gets(end->name);
//	printf("请输入分数（输入0结束）");
//	scanf("%d",&end->score); 
	head=end;
	counter++;
	while(nnew->score!=0) 
	{ 
	  counter++;
	  nnew=(struct nba *)malloc(sizeof(struct nba));
	  printf("请输入球员姓名："); 
//	  gets(nnew->name);
	  scanf("%s",nnew->name);
	  printf("输入分数(输入0结束！)\n");
	  scanf("%d",&nnew->score);
	  printf("请输入篮板数：");
	  scanf("%f",&nnew->rebound);                                              //******
	  end->next=nnew;
	  end=nnew;
	} 
	end->next=NULL;
	counter=counter-2;
	printf("个数有%d个\n",counter);
    return head;
}
void print(struct nba *head)                     //打印函数 
{
	int i=1;
	struct nba *po;
	po=head->next;
//	printf("打印链表为：\n"); 
	while(po->next!=NULL)
	{
		printf("\n第%d名球员是：\n",i);
		printf("姓名：");
		puts(po->name);
		printf("得分：%d  ",po->score);
		printf("篮板：%.1f\n",po->rebound);                                 //******
		po=po->next;
		i++; 
	}
}
void filee(struct nba *stu)                      //写文件函数 
{
	FILE *fp;
	char filename[20];
//	printf("输入文件名：");
	strcpy(filename,"fi.txt");
	fp=fopen(filename,"r");
	struct nba *head;
	head=stu;
	while(head->next!=NULL)
	{
	  fprintf(fp,"%s",head->name);
	  fprintf(fp,"%d",head->score);
	  fprintf(fp,"%f\n",head->rebound);                                        //******
	  head=head->next;
	}
	printf("文件写入成功!");
	fclose(fp);
}
struct nba *write()                          //读取文件函数 ，并打印 
{
	counter=-1; 
	char fname[20];
	struct nba *head;
	struct nba *pnew,*pend;
	FILE *fp;
	strcpy(fname,"fi.txt");
	fp=fopen(fname,"r");
	head=(struct nba *)malloc(sizeof(struct nba)); 
	head->next=NULL;
	pnew=head;
	while(!feof(fp))
	{
		counter++;
		pend=(struct nba *)malloc(sizeof(struct nba));
        fscanf(fp,"%s",pend->name);
        fscanf(fp,"%d",&pend->score); 
        fscanf(fp,"%f",&pend->rebound);                                       //******
		pnew->next=pend;
		pnew=pend;

	}
	fclose(fp);
	pend->next=NULL;
	printf("读文件成功！！！有%d个球员",counter); 
	return head;
}
void sort_score (struct nba *head) 
{                                                    //排序函数（改变原链表 ） 
     struct nba *p;  
     struct nba *r;  
     char na[20];  
     int temp;  
     int i,j,k1,k2;
     float te;
     printf("按得分排序请按1；按篮板排序请按2：  ") ;
     scanf("%d",&j);
     switch(j)
	 {
	 	case 1:   
		printf("按升序排列请按1；按降序排列请按2：");
		scanf("%d",&k1);
		switch(k1)
		{
			case 1:
				for(i=0;i<counter;i++)
                {
     	          p = head;  
                  r = p->next;  
                  while (r->next!= NULL) 
				  {  
                      if (p->score > r->score) 
		              {  
                          temp = p->score;  
                          p->score = r->score;  
                          r->score = temp;  
            
                          strcpy(na,p->name);
                          strcpy(p->name,r->name);
                          strcpy(r->name,na);
            
                          te=p->rebound;
                          p->rebound=r->rebound;                                 //******
                          r->rebound=te;
            
                      }    
                      p = p->next;  
                      r = r->next;   
                 } 
	    
	            }
	       break;
				
				
				
				
				
			
			case 2:
				for(i=0;i<counter;i++)
                {
     	          p = head->next;  
                  r = p->next;  
                  while (r->next!= NULL) 
				  {  
                      if (p->score < r->score) 
		              {  
                          temp = p->score;  
                          p->score = r->score;  
                          r->score = temp;  
            
                          strcpy(na,p->name);
                          strcpy(p->name,r->name);
                          strcpy(r->name,na);
            
                          te=p->rebound;
                          p->rebound=r->rebound;                                 //******
                          r->rebound=te;
                      }    
                      p = p->next;  
                      r = r->next;   
                 } 
	            }
				break;
		}
		break;
		

	   
	   
	   
	  case 2:
	  	printf("按升序排列请按1；按降序排列请按2：");
		scanf("%d",&k1);
		switch(k1)
		{
			case 1:
		    for(i=0;i<counter;i++)
            {
     	      p = head;  
              r = p->next;  
              while (r->next!= NULL) {  
              if (p->rebound > r->rebound) 
		      {  
                temp = p->score;  
                p->score = r->score;  
                r->score = temp;  
            
                strcpy(na,p->name);
                strcpy(p->name,r->name);
                strcpy(r->name,na);
            
                te=p->rebound;
                p->rebound=r->rebound;                                        //******
                r->rebound=te;
            
             }  
             p = p->next;  
             r = r->next;   
            }  
	       }
				
				
				
				
				
				
				
				break;
			case 2:
				for(i=0;i<counter;i++)
            {
     	      p = head->next;  
              r = p->next;  
              while (r->next!= NULL) {  
              if (p->rebound < r->rebound) 
		      {  
                temp = p->score;  
                p->score = r->score;  
                r->score = temp;  
            
                strcpy(na,p->name);
                strcpy(p->name,r->name);
                strcpy(r->name,na);
            
                te=p->rebound;
                p->rebound=r->rebound;                                        //******
                r->rebound=te;
            
             }  
             p = p->next;  
             r = r->next;   
            }  
	       }
				
				
				
				
				
				
				
				
				break;
		}
	  
	 break;
	   
	  }
} 
 void modify(struct nba *head)                    //修改函数 
 {
 	struct nba *stu;
 	char newname[20];
 	int sc,sw,re;
 	stu=head;
	printf("请输入要修改的球员：");
	scanf("%s",newname);
	printf("要修改得分选择1；篮板选择2: ");
	scanf("%d",&sw);
	switch(sw)
	{
		  case 1:
	      printf("输入要修改的分数：");
	      scanf("%d",&sc);
	      while(stu->next!=NULL)
	      {
		    if(!strcmp(stu->name,newname))
		    {
			  stu->score=sc;
			  break;
		    }
		    stu=stu->next;
	      }
	      break;
	      case 2:
	      printf("输入要修改的篮板：");
	      scanf("%f",&re);
	      while(stu->next!=NULL)
	      {
	      	if(!strcmp(stu->name,newname))                                      //******
	      	{
	      		stu->rebound=re;
	      		break;
			  }
		    stu=stu->next;
	      
		  }
		  break;
	      
	}

	printf("修复后的链表为：\n");
  } 
void query(struct nba *head)                     //查找函数 
{
	float sscore,ssreb;
	int sw;
	int flag=0;
	struct nba *stu;
	stu=head;
	char qname[20];
	printf("按姓名查找请按1；      按得分查找请按2；      得分·篮板组合查找请按3：");
	scanf("%d",&sw);
	switch(sw)
	{
		case 1:
			printf("输入要查询数据的球员姓名：");
	        scanf("%s",qname);
	        while(stu->next!=NULL)
	        {
		        if(!strcmp(stu->name,qname))
		          {
			        printf("查询信息：");
		        	puts(stu->name);
			        printf("得分：%d  ",stu->score);
			        printf("篮板：%.1f",stu->rebound);      
					flag=1;                                                     //******
			        break;
		          }
		        
		        stu=stu->next;
	       }  
		   if(flag=0)
		        {
		        	printf("输入的姓名不存在！！");
				}      
			
			
			
			break;
		case 2:
			flag=0;
			stu=head;
			printf("请输入要查询球员的得分：");
			scanf("%f",&sscore);
			while(stu->next!=NULL)
			{
				if(sscore==stu->score)
				{
					printf("查询信息：");
					puts(stu->name);
					printf("得分：%d  ",stu->score);
					printf("篮板：%.1f",stu->rebound);
					flag=1;
//					break;
				}
				
				stu=stu->next;
				
			}
			if(flag==0)
				{
					printf("输入的得分不存在！!");
				}			
			
			
			
			break;
		case 3:
			printf("请输入得分：");
			scanf("%f",&sscore);
			printf("请输入篮板：");
			scanf("%f",&ssreb); 
			flag=0;
			stu=head;
			while(stu->next!=NULL)
			{
				  if(stu->score==sscore&&stu->rebound==ssreb)
			      {
				      printf("查询信息：");
				      puts(stu->name);
				      printf("得分：%d  ",stu->score); 
				      printf("篮板：%.1f",stu->rebound);
				      flag=1;
				      break;
				      
			      }
			      
				  stu=stu->next; 
			}
			if(flag==0)
			      {
			      	  printf("输入不存在！！");
				  }

			
			
			
			break; 

			 
	}
	 
}
void insert(struct nba *head)                   //插入新球员 
{
	
	struct nba *stu,*stu1,*nnew;
	stu=head;
//	stu->next=stu1;
	char iname[20];
	printf("要将新球员插入哪一名球员之后");
	scanf("%s",iname);
	nnew=(struct nba *)malloc(sizeof(struct nba));
	printf("输入新球员姓名");
	scanf("%s",nnew->name);
	printf("输入新球员的得分"); 
	scanf("%d",&nnew->score);
	printf("输入新球员的篮板");
	scanf("%f",&nnew->rebound);                                               //******
	while(stu->next!=NULL)
	{
		if(!strcmp(iname,stu->name))
		{
			stu1=stu->next;
			nnew->next=stu1;
			stu->next=nnew;
		}
		stu=stu->next;
	 } 
	printf("插入后的链表为；");
}
void deletee(struct nba *head)                  //删除函数 
{
	char nname[20];
	struct nba *stu,*stu2,*stu1;
	stu=head;
	printf("请输入要删除的球员的姓名：");
	scanf("%s",nname);
	while(stu->next!=NULL)
	{
		stu1=stu->next;
		stu2=stu1->next;
		if(!strcmp(nname,stu1->name))
		{
			stu->next=stu2;
			
		}
		stu=stu->next;
	 } 
	 free(stu1);
}
void face()                                           //打印界面 
{
	printf("\n\n\n");
	printf("            ********************************************\n");
	printf("            --------------------------------------------\n");
	printf("\n");
	printf("            |         欢迎使用NBA球星管理系统          |\n");
	printf("\n");
	printf("            --------------------------------------------\n"); 
	
	printf("            |           1-手动录入球员信息             |\n");
	printf("            |           2-文件录入球员信息             |\n"); 
	printf("            ********************************************\n");
	printf("\n            请先登陆"); 
	printf("\n\n\n");
 } 
void face2()                                           //打印界面 2
{
	printf("\n\n\n");
	printf("            ********************************************\n");
	printf("            --------------------------------------------\n");
	printf("\n");
	printf("            |         欢迎使用NBA球星管理系统          |\n");
	printf("\n");
	printf("            --------------------------------------------\n"); 
	printf("            |           3-显示所有球员信息             |\n");
	printf("            |           4-查询球员信息                 |\n");
	printf("            |           5-将数据读出到文件             |\n");
	printf("            |          *6-修改某个球员信息             |\n");
	printf("            |          *7-删除某个球员信息             |\n");
	printf("            |          *8-增添新球员信息               |\n");
	printf("            |           9-按条件顺序输出球员信息       |\n"); 
	printf("            |           10-球员信息统计                |\n");
	printf("            |           11-数据报表                    |\n");
	printf("            |           12-球员对比                    |\n");
	printf("            |           13-退出                        |\n"); 
	printf("            ********************************************\n");
	printf("            |                 （*表示需取得管理员身份) |\n");
	printf("\n\n\n");
 } 
void statis(struct nba *head)                      //数据统计函数 （平均值，最大最小值） 
{
	struct nba *stuu,*stu1,*stu2,*flag1,*flag2,*flag3,*flag4;
	stuu=head->next;
	int min,max;
	float  sum=0,sumrebound=0,minreb,maxreb;
	while(stuu->next!=NULL)
	{
		sum+=stuu->score;
		sumrebound+=stuu->rebound;
		stuu=stuu->next;
	}
	avescore=sum/counter;
	averebound=sumrebound/counter;
	printf("平均得分为：%.2f      ",avescore);
	printf("平均篮板数为：%.2f",averebound);
	stu2=stu1=head->next;
	max=min=stu1->score;
	while(stu1->next!=NULL)
	{
		if(stu1->score>max)
		{ 
	        max=stu1->score;
	        flag1=stu1;
	    } 
	    else if(stu1->score<min)
	    {
	    	min=stu1->score;
	    	flag2=stu1;
	    	
		}
	    
	    stu1=stu1->next;
	}
//	stu1=head->next;
    maxreb=minreb=stu2->rebound;
	while(stu2->next!=NULL)
	{
		if(stu2->rebound>maxreb)
		{ 
	        maxreb=stu2->rebound;
	        flag3=stu2;                                                           //******
	    } 
	    else if(stu2->rebound<minreb)
	    {
	    	minreb=stu2->rebound;
	    	flag4=stu2;
	    	
		}
	    
	    stu2=stu2->next;
	}
	printf("\n最低得分%d   最高得分%d\n",min,max);
	printf("最低篮板数%.1f   最高篮板数%.1f\n",minreb,maxreb);
	printf("最高得分球员为：");
	puts(flag1->name);
	printf("最低得分球员为：");
	puts(flag2->name); 
	printf("最高篮板球员为：");                                                   //******
	puts(flag3->name);
	printf("最低篮板球员为：");
	puts(flag4->name);
 } 
void landing()                                     //登陆函数 
{
    char password[10]="123456",guan1[10]="A",guan2[10]="P";
    char password1[10],guan3[10];
    int icount=2,flag=0,i;
    printf("            管理员或游客？管理员选择A，游客选择P\n");
    while(flag==0)
	{
	  scanf("%s",guan3);  
      if(!strcmp(guan3,guan2))
      {
    	  printf("进入游客模式成功！"); 
      	  flag=1;
	  }
	  if(!strcmp(guan3,guan1))
	  {
	  	  printf("请输入管理员密码：");
	  	  
	  	  
	  	  for(i=0;i<6;i++)
	      {
		      password1[i]=getch();
		      printf("*"); 
	      }
//		  scanf("%s",password1);
		  
		  
		  
		  if(!strcmp(password1,password))
		  {
			  printf("进入管理员模式成功！，可进行信息的删除，修改，插入等操作");
			  flag=1;
			  root=1;
			  
		  }
		  if(strcmp(password1,password))
		  while(icount>0)
		  {
			  printf("密码输入错误!请重新输入.(您还有%d此机会)\n",icount);
			  
			  for(i=0;i<6;i++)
	          {
		         password1[i]=getch();
               printf("*"); 
            }
//			  scanf("%s",password1);
			  --icount;
			  if(!strcmp(password,password1))
			  {
			  	printf("进入管理员模式成功！，可进行信息的删除，修改，插入等操作");
			  	root=1;
			  	flag=1;
			  	break;
			  	
//			  	break;
			  }
			  if(icount==0)
			  {
				  printf("您的机会已用完！请联系党森林"); 
				  flag=1;
			  }
		  }
	  }
	else if(flag==0)
	printf("请输入正确的选项！\n");
	
    }
 } 
int statement(struct nba *head)                         //报表函数 
{
	int fflag=0;
	struct nba *stu1;
	stu1=head->next;
	while(stu1->next!=NULL)
    {
    	if(stu1->score>avescore)
    	{
    		stu1->fl=1;
		}
		else
		stu1->fl=0;
		stu1=stu1->next;
	}
	stu1=head->next;
	printf("得分高于平均分的球员有：\n");
	while(stu1->next!=NULL)
	{
		if(stu1->fl==1)
		puts(stu1->name);
		stu1=stu1->next;
		
	}
	stu1=head->next;
	printf("得分低于平均分的球员有：\n");
	while(stu1->next!=NULL)
	{
		if(stu1->fl==0)
		puts(stu1->name);
		stu1=stu1->next;
	 } 
	 stu1=head->next;
	 while(stu1->next!=NULL)
	 {
	 	if(stu1->rebound>averebound)
	 	{
	 		stu1->fl=1;
		 }
		 else
		 stu1->fl=0;
		 stu1=stu1->next;
	 }
	 stu1=head->next; 
	 printf("\n\n\n篮板高于平均篮板数的球员有：\n");
	 while(stu1->next!=NULL)
	 {
	 	if(stu1->fl==1)
	 	puts(stu1->name);
		stu1=stu1->next; 
	 }
	 stu1=head->next;
	 printf("篮板少于平均篮板数的球员有：\n");
	 while(stu1->next!=NULL)
     {
     	if(stu1->fl==0)
		 puts(stu1->name);
		 stu1=stu1->next; 
	 } 
	  
}
int compare(struct nba *head)                         //球员对比函数 
{
	int num;
	struct nba *stu1,*stui,*stuj;
	char namei[10],namej[10];
	stu1=head->next;
	printf("请输入要对比的第一名球员："); 
	scanf("%s",namei);
	printf("请输入要对比的第二名球员：");
	scanf("%s",namej);
	while(stu1->next!=NULL)
	{
		if(!strcmp(stu1->name,namei))
		stui=stu1;
		stu1=stu1->next;
	}
	stu1=head->next;
	while(stu1->next!=NULL)
	{
		if(!strcmp(stu1->name,namej))
		stuj=stu1;
		stu1=stu1->next;
	}
	printf("\n得分对比：");
	if(stui->score>stuj->score)
	printf("%s胜\n",stui->name);
	else
	printf("%s胜\n",stuj->name);
	printf("%s:",stui->name);
	num=stui->score;
	for(int i=0;i<num;i++)
	{
		printf("%c",43);
	}
	printf("\n%s:",stuj->name);
	num=stuj->score;
	for(int i=0;i<num;i++)
    {
    	printf("%c",43);
	}
	printf("\n\n篮板对比：");
	if(stui->rebound>stuj->rebound)
	printf("%s胜\n",stui->name);
	else
	printf("%s胜\n",stuj->name);
	printf("%s",stui->name);
	num=stui->rebound*10;
	for(int i=0;i<num;i++)
	printf("%c",43);
	num=stuj->rebound*10;
	printf("\n%s",stuj->name);
	for(int i=0;i<num;i++)
	printf("%c",43); 
//	printf("%.1f     %.1f",stui->rebound,stuj->rebound); 
}


void sect()                                  //选择操作函数 
{
	struct nba *head; 
	int number,num11,num12;
	int flag=0;
	printf("请输入数字 1 or 2 :");
	scanf("%d",&number);
	switch(number)
	{
		case 1:
		head=create();
		while(flag!=1)
		{
			face2();
		    printf("请选择3~~10(选择11退出)"); 
		    scanf("%d",&num11);
		    switch(num11)
		    {
			 
			case 3:print(head); 
			       break; 
		    case 4:query(head);
			       break; 
		    case 5:filee(head);
			       printf("读出文件成功！");
			       print(head); 
				   break;
			case 6:if(root==1)
			       {
			       	 modify(head);
			         print(head); 
				     break;
				   }
				   else
				   {
				   	printf("请获取管理员权限！");
				   	break;
				   }
			        
			case 7:if(root==1)
			       {
			       	 deletee(head);
			         print(head);  
				     break;
				   }
				   else
				   {
				   	printf("请获取管理员权限！");
				   	break;
				   }
			case 8:if(root==1)
			       {
			       	 insert(head);
			         print(head); 
				     break;
					} 
					else
					{
						printf("请获取管理员权限！");
						break;
					}
		    case 9:sort_score(head);
		           print(head);
		           break;
		    case 10:statis(head);
		           break;
		    case 11:statement(head);
		            break;
		    case 12:compare(head);
		            break;
			case 13:flag=1;
			        break; 
		    }
		
		}
		break;
		case 2:
			head=write();
			while(flag!=1) 
			{
				face2();
		    printf("请选择3~~10(选择11退出)"); 
		    scanf("%d",&num11);
		    switch(num11)
		    {
			 
			case 3:print(head); 
			       break; 
			case 4:query(head);
			       break;
		    case 5:filee(head);
			       printf("读出文件成功！");
			       print(head); 
				   break;
			case 6:if(root==1)
			       {
			       	  modify(head);
			          print(head); 
				      break;
			       	
					} 
					else
					{
						printf("请获取管理员权限！");
						break;
					 } 
			        
			case 7:if(root==1)
			       {
			       	   deletee(head);
			           print(head);  
				       break;
			       	
				   }
				   else
				   {
				   	printf("请获取管理员权限！");
				   	break;
				   }
 
			case 8:if(root==1)
			       {
			       	 insert(head);
			         print(head); 
				     break;
					} 
					else
					{
						printf("请获取管理员权限！");
						break;
					}
		    case 9:sort_score(head);
		           print(head);
		           break;
		    case 10:statis(head);
		           break;
		    case 11:statement(head);
		            break;
		    case 12:compare(head);
		            break;
			case 13:flag=1;
			        break; 
			}
		}
		break; 
	}
}

int main()
{
//	int number;
//	struct nba *head;
//	head=create();
    face();
	landing();
	sect();
//	printf("请输入数字1~~7");
//	scanf("%d",&number); 
//	statis(head);
//	print(head);
//	deletee(head); 
    
//    head=write();
//	printf("打印链表"); 
//	print(head);
//	insert(head);
//	print(head);
//	query(head); 
//	filee(head);
//    modify(head);
//  sort_score(head);
//  printf("排序后的链表");
//    print(head); 
    return 0;
}
