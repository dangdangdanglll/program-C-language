#include<stdio.h>
enum weekday {Tuesday,Wedneaday,Thursday,Friday,Saturday,Sunday,Monday}stu1;
struct date
{
	 int year;
	 int month;
	 int day;
	 enum  weekday stu1;

};
main()
{
	struct date stu;
	int m,d,days,j,i,k;
	int daysy=0,daysm=0;
	int arr[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	printf("请输入年:");
    scanf("%d",&stu.year);
	printf("请输入月:");
	scanf("%d",&stu.month);
	printf("请输入日:");
	scanf("%d",&stu.day);
	j=(stu.year-1980)/4;
	daysy=(stu.year-1980)*365+j+1;
	if(stu.year==1980)
	  daysy=0;
	for(i=0;i<stu.month-1;i++)
		daysm+=arr[i];
	if((stu.year%4==0&&stu.year%100!=0||stu.year%400==0)&&stu.month>2)
		daysm++;
	days=daysy+daysm +stu.day-1;
	k=days%7;
	printf("%d年 %d月 %d日   星期%d",stu.year,stu.month,stu.day,k+2);






	



}
