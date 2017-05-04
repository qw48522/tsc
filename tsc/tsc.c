#include<stdio.h>
#include<stdlib.h>
typedef struct date
{
	int year;
	int month;
	int day;
}* pdate;
void getdate(pdate a)
{
    printf("Year:\n");
	scanf("%d",&a->year);
    printf("Month:\n");
	scanf("%d",&a->month);
	printf("Day:\n");
	scanf("%d",&a->day);
}
int bj(pdate a,pdate b)
{
	if(a->year>b->year)
		return 1;
	else if(a->year<b->year)
		return 0;
	else
	{
		if(a->month>b->month)
		    return 1;
	    else if(a->month<b->month)
		    return 0;
	    else
		{
            if(a->day>b->day)
		         return 1;
	        else
				return 0;
		}
	}
}
int day(pdate a)
{
    int i;
	int f=0;
	for(i=a->month;i>=1;i--)
	{
		if(i==a->month)
			f+=a->day;
		else
		{
            if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			    f+=31;
		    else if(i==2)
			{
			    if((a->year%4==0&&a->year%100!=0)||a->year%400==0)
			        f+=29;
		     	else
				    f+=28;
			}
		    else
			    f+=30;
		}
    }
	return f;
}
int tsc(pdate a,pdate b)
{
    int i;
	int f1=0,f2=0,f3=0;
	for(i=b->year;i<a->year;i++)
	{
		if((i%4==0&&i%100!=0)||i%400==0)
             f1+=366;
		else
			 f1+=365;
	}
    f2=day(a);
	f3=day(b);
	return f1+f2-f3;
}
void main()
{
	pdate a,b;
    a=(pdate)malloc(sizeof(struct date));
    b=(pdate)malloc(sizeof(struct date));
    getdate(a);
	getdate(b);
	int i;
	i=(bj(a,b)?tsc(a,b):tsc(b,a));
    printf("ÌìÊı²î£º%d\n",i);
}
