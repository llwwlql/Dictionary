#include <stdio.h>
int fun(int year)
{
	if(year%4==0 && year%100!=0 || year%400==0)
		return 1;
	else
		return 0;
}

int main()
{
	int T;
	int year,month,day;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d-%d-%d",&year,&month,&day);
		if(fun(year) && month==2 && day==29)
			printf("-1\n");
		else
		{
			int sum=0,temp;
			if(month<=2)
				temp=0;
			else
				temp=1;
			for(int i=temp;i<=17+temp;i++)
			{
				sum+=365;
				if(fun(year+i))
					sum++;
			}
			printf("%d\n",sum);
		}
	}
	
	return 0;
}
