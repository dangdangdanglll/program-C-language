#include<stdio.h>           //��д���ļ� ,������ 
#include<string.h>           //���⣺ִֻ�д�������������bug(ͷ�ڵ�) 
#include<stdlib.h>          //       ��һ�ε�½���󣬵ڶ��ε�½��ȷʱѡ��bug 
#include<conio.h>
int root=0;
float avescore=0,averebound=0;
struct nba                      //���� 
{
	char name[20];
	int score; 
	float rebound;  
	int fl;                                                     //******
	struct nba *next; 
}stu; 
int counter=0;
struct nba *create()                         //���������� 
{
	struct nba *head=NULL;
	struct nba *nnew,*end;
	end=(struct nba *)malloc(sizeof(struct nba));
//	printf("��������Ա������");
//	gets(end->name);
//	printf("���������������0������");
//	scanf("%d",&end->score); 
	head=end;
	counter++;
	while(nnew->score!=0) 
	{ 
	  counter++;
	  nnew=(struct nba *)malloc(sizeof(struct nba));
	  printf("��������Ա������"); 
//	  gets(nnew->name);
	  scanf("%s",nnew->name);
	  printf("�������(����0������)\n");
	  scanf("%d",&nnew->score);
	  printf("��������������");
	  scanf("%f",&nnew->rebound);                                              //******
	  end->next=nnew;
	  end=nnew;
	} 
	end->next=NULL;
	counter=counter-2;
	printf("������%d��\n",counter);
    return head;
}
void print(struct nba *head)                     //��ӡ���� 
{
	int i=1;
	struct nba *po;
	po=head->next;
//	printf("��ӡ����Ϊ��\n"); 
	while(po->next!=NULL)
	{
		printf("\n��%d����Ա�ǣ�\n",i);
		printf("������");
		puts(po->name);
		printf("�÷֣�%d  ",po->score);
		printf("���壺%.1f\n",po->rebound);                                 //******
		po=po->next;
		i++; 
	}
}
void filee(struct nba *stu)                      //д�ļ����� 
{
	FILE *fp;
	char filename[20];
//	printf("�����ļ�����");
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
	printf("�ļ�д��ɹ�!");
	fclose(fp);
}
struct nba *write()                          //��ȡ�ļ����� ������ӡ 
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
	printf("���ļ��ɹ���������%d����Ա",counter); 
	return head;
}
void sort_score (struct nba *head) 
{                                                    //���������ı�ԭ���� �� 
     struct nba *p;  
     struct nba *r;  
     char na[20];  
     int temp;  
     int i,j,k1,k2;
     float te;
     printf("���÷������밴1�������������밴2��  ") ;
     scanf("%d",&j);
     switch(j)
	 {
	 	case 1:   
		printf("�����������밴1�������������밴2��");
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
	  	printf("�����������밴1�������������밴2��");
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
 void modify(struct nba *head)                    //�޸ĺ��� 
 {
 	struct nba *stu;
 	char newname[20];
 	int sc,sw,re;
 	stu=head;
	printf("������Ҫ�޸ĵ���Ա��");
	scanf("%s",newname);
	printf("Ҫ�޸ĵ÷�ѡ��1������ѡ��2: ");
	scanf("%d",&sw);
	switch(sw)
	{
		  case 1:
	      printf("����Ҫ�޸ĵķ�����");
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
	      printf("����Ҫ�޸ĵ����壺");
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

	printf("�޸��������Ϊ��\n");
  } 
void query(struct nba *head)                     //���Һ��� 
{
	float sscore,ssreb;
	int sw;
	int flag=0;
	struct nba *stu;
	stu=head;
	char qname[20];
	printf("�����������밴1��      ���÷ֲ����밴2��      �÷֡�������ϲ����밴3��");
	scanf("%d",&sw);
	switch(sw)
	{
		case 1:
			printf("����Ҫ��ѯ���ݵ���Ա������");
	        scanf("%s",qname);
	        while(stu->next!=NULL)
	        {
		        if(!strcmp(stu->name,qname))
		          {
			        printf("��ѯ��Ϣ��");
		        	puts(stu->name);
			        printf("�÷֣�%d  ",stu->score);
			        printf("���壺%.1f",stu->rebound);      
					flag=1;                                                     //******
			        break;
		          }
		        
		        stu=stu->next;
	       }  
		   if(flag=0)
		        {
		        	printf("��������������ڣ���");
				}      
			
			
			
			break;
		case 2:
			flag=0;
			stu=head;
			printf("������Ҫ��ѯ��Ա�ĵ÷֣�");
			scanf("%f",&sscore);
			while(stu->next!=NULL)
			{
				if(sscore==stu->score)
				{
					printf("��ѯ��Ϣ��");
					puts(stu->name);
					printf("�÷֣�%d  ",stu->score);
					printf("���壺%.1f",stu->rebound);
					flag=1;
//					break;
				}
				
				stu=stu->next;
				
			}
			if(flag==0)
				{
					printf("����ĵ÷ֲ����ڣ�!");
				}			
			
			
			
			break;
		case 3:
			printf("������÷֣�");
			scanf("%f",&sscore);
			printf("���������壺");
			scanf("%f",&ssreb); 
			flag=0;
			stu=head;
			while(stu->next!=NULL)
			{
				  if(stu->score==sscore&&stu->rebound==ssreb)
			      {
				      printf("��ѯ��Ϣ��");
				      puts(stu->name);
				      printf("�÷֣�%d  ",stu->score); 
				      printf("���壺%.1f",stu->rebound);
				      flag=1;
				      break;
				      
			      }
			      
				  stu=stu->next; 
			}
			if(flag==0)
			      {
			      	  printf("���벻���ڣ���");
				  }

			
			
			
			break; 

			 
	}
	 
}
void insert(struct nba *head)                   //��������Ա 
{
	
	struct nba *stu,*stu1,*nnew;
	stu=head;
//	stu->next=stu1;
	char iname[20];
	printf("Ҫ������Ա������һ����Ա֮��");
	scanf("%s",iname);
	nnew=(struct nba *)malloc(sizeof(struct nba));
	printf("��������Ա����");
	scanf("%s",nnew->name);
	printf("��������Ա�ĵ÷�"); 
	scanf("%d",&nnew->score);
	printf("��������Ա������");
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
	printf("����������Ϊ��");
}
void deletee(struct nba *head)                  //ɾ������ 
{
	char nname[20];
	struct nba *stu,*stu2,*stu1;
	stu=head;
	printf("������Ҫɾ������Ա��������");
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
void face()                                           //��ӡ���� 
{
	printf("\n\n\n");
	printf("            ********************************************\n");
	printf("            --------------------------------------------\n");
	printf("\n");
	printf("            |         ��ӭʹ��NBA���ǹ���ϵͳ          |\n");
	printf("\n");
	printf("            --------------------------------------------\n"); 
	
	printf("            |           1-�ֶ�¼����Ա��Ϣ             |\n");
	printf("            |           2-�ļ�¼����Ա��Ϣ             |\n"); 
	printf("            ********************************************\n");
	printf("\n            ���ȵ�½"); 
	printf("\n\n\n");
 } 
void face2()                                           //��ӡ���� 2
{
	printf("\n\n\n");
	printf("            ********************************************\n");
	printf("            --------------------------------------------\n");
	printf("\n");
	printf("            |         ��ӭʹ��NBA���ǹ���ϵͳ          |\n");
	printf("\n");
	printf("            --------------------------------------------\n"); 
	printf("            |           3-��ʾ������Ա��Ϣ             |\n");
	printf("            |           4-��ѯ��Ա��Ϣ                 |\n");
	printf("            |           5-�����ݶ������ļ�             |\n");
	printf("            |          *6-�޸�ĳ����Ա��Ϣ             |\n");
	printf("            |          *7-ɾ��ĳ����Ա��Ϣ             |\n");
	printf("            |          *8-��������Ա��Ϣ               |\n");
	printf("            |           9-������˳�������Ա��Ϣ       |\n"); 
	printf("            |           10-��Ա��Ϣͳ��                |\n");
	printf("            |           11-���ݱ���                    |\n");
	printf("            |           12-��Ա�Ա�                    |\n");
	printf("            |           13-�˳�                        |\n"); 
	printf("            ********************************************\n");
	printf("            |                 ��*��ʾ��ȡ�ù���Ա���) |\n");
	printf("\n\n\n");
 } 
void statis(struct nba *head)                      //����ͳ�ƺ��� ��ƽ��ֵ�������Сֵ�� 
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
	printf("ƽ���÷�Ϊ��%.2f      ",avescore);
	printf("ƽ��������Ϊ��%.2f",averebound);
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
	printf("\n��͵÷�%d   ��ߵ÷�%d\n",min,max);
	printf("���������%.1f   ���������%.1f\n",minreb,maxreb);
	printf("��ߵ÷���ԱΪ��");
	puts(flag1->name);
	printf("��͵÷���ԱΪ��");
	puts(flag2->name); 
	printf("���������ԱΪ��");                                                   //******
	puts(flag3->name);
	printf("���������ԱΪ��");
	puts(flag4->name);
 } 
void landing()                                     //��½���� 
{
    char password[10]="123456",guan1[10]="A",guan2[10]="P";
    char password1[10],guan3[10];
    int icount=2,flag=0,i;
    printf("            ����Ա���οͣ�����Աѡ��A���ο�ѡ��P\n");
    while(flag==0)
	{
	  scanf("%s",guan3);  
      if(!strcmp(guan3,guan2))
      {
    	  printf("�����ο�ģʽ�ɹ���"); 
      	  flag=1;
	  }
	  if(!strcmp(guan3,guan1))
	  {
	  	  printf("���������Ա���룺");
	  	  
	  	  
	  	  for(i=0;i<6;i++)
	      {
		      password1[i]=getch();
		      printf("*"); 
	      }
//		  scanf("%s",password1);
		  
		  
		  
		  if(!strcmp(password1,password))
		  {
			  printf("�������Աģʽ�ɹ������ɽ�����Ϣ��ɾ�����޸ģ�����Ȳ���");
			  flag=1;
			  root=1;
			  
		  }
		  if(strcmp(password1,password))
		  while(icount>0)
		  {
			  printf("�����������!����������.(������%d�˻���)\n",icount);
			  
			  for(i=0;i<6;i++)
	          {
		         password1[i]=getch();
               printf("*"); 
            }
//			  scanf("%s",password1);
			  --icount;
			  if(!strcmp(password,password1))
			  {
			  	printf("�������Աģʽ�ɹ������ɽ�����Ϣ��ɾ�����޸ģ�����Ȳ���");
			  	root=1;
			  	flag=1;
			  	break;
			  	
//			  	break;
			  }
			  if(icount==0)
			  {
				  printf("���Ļ��������꣡����ϵ��ɭ��"); 
				  flag=1;
			  }
		  }
	  }
	else if(flag==0)
	printf("��������ȷ��ѡ�\n");
	
    }
 } 
int statement(struct nba *head)                         //������ 
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
	printf("�÷ָ���ƽ���ֵ���Ա�У�\n");
	while(stu1->next!=NULL)
	{
		if(stu1->fl==1)
		puts(stu1->name);
		stu1=stu1->next;
		
	}
	stu1=head->next;
	printf("�÷ֵ���ƽ���ֵ���Ա�У�\n");
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
	 printf("\n\n\n�������ƽ������������Ա�У�\n");
	 while(stu1->next!=NULL)
	 {
	 	if(stu1->fl==1)
	 	puts(stu1->name);
		stu1=stu1->next; 
	 }
	 stu1=head->next;
	 printf("��������ƽ������������Ա�У�\n");
	 while(stu1->next!=NULL)
     {
     	if(stu1->fl==0)
		 puts(stu1->name);
		 stu1=stu1->next; 
	 } 
	  
}
int compare(struct nba *head)                         //��Ա�ԱȺ��� 
{
	int num;
	struct nba *stu1,*stui,*stuj;
	char namei[10],namej[10];
	stu1=head->next;
	printf("������Ҫ�Աȵĵ�һ����Ա��"); 
	scanf("%s",namei);
	printf("������Ҫ�Աȵĵڶ�����Ա��");
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
	printf("\n�÷ֶԱȣ�");
	if(stui->score>stuj->score)
	printf("%sʤ\n",stui->name);
	else
	printf("%sʤ\n",stuj->name);
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
	printf("\n\n����Աȣ�");
	if(stui->rebound>stuj->rebound)
	printf("%sʤ\n",stui->name);
	else
	printf("%sʤ\n",stuj->name);
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


void sect()                                  //ѡ��������� 
{
	struct nba *head; 
	int number,num11,num12;
	int flag=0;
	printf("���������� 1 or 2 :");
	scanf("%d",&number);
	switch(number)
	{
		case 1:
		head=create();
		while(flag!=1)
		{
			face2();
		    printf("��ѡ��3~~10(ѡ��11�˳�)"); 
		    scanf("%d",&num11);
		    switch(num11)
		    {
			 
			case 3:print(head); 
			       break; 
		    case 4:query(head);
			       break; 
		    case 5:filee(head);
			       printf("�����ļ��ɹ���");
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
				   	printf("���ȡ����ԱȨ�ޣ�");
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
				   	printf("���ȡ����ԱȨ�ޣ�");
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
						printf("���ȡ����ԱȨ�ޣ�");
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
		    printf("��ѡ��3~~10(ѡ��11�˳�)"); 
		    scanf("%d",&num11);
		    switch(num11)
		    {
			 
			case 3:print(head); 
			       break; 
			case 4:query(head);
			       break;
		    case 5:filee(head);
			       printf("�����ļ��ɹ���");
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
						printf("���ȡ����ԱȨ�ޣ�");
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
				   	printf("���ȡ����ԱȨ�ޣ�");
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
						printf("���ȡ����ԱȨ�ޣ�");
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
//	printf("����������1~~7");
//	scanf("%d",&number); 
//	statis(head);
//	print(head);
//	deletee(head); 
    
//    head=write();
//	printf("��ӡ����"); 
//	print(head);
//	insert(head);
//	print(head);
//	query(head); 
//	filee(head);
//    modify(head);
//  sort_score(head);
//  printf("����������");
//    print(head); 
    return 0;
}
