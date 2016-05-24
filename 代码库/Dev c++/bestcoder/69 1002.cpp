#include <stdio.h>
char str[20];
int peace1()
{
	if(str[6]==str[7] && str[7]==str[8] && str[8]==str[9] && str[9]==str[10])
		return 1;
	return 0;
}

int peace2()
{
	if(str[6]-str[7] == str[7]-str[8] && str[7]-str[8] == str[8]-str[9] && str[9]-str[10] == str[8]-str[9])
		return 1;
	return 0;
}

int peace4(int year,int month,int day)
{
	if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10|| month==12))
	{
		if(day>=1 && day<=31)
			return 1;
		return 0;
	}
	
	else if(month==2 && (year%4==0 && year%100 !=0 || year %400 ==0))
	{
		if(day>=1 && day<=29)
			return 1;
		return 0;
	}
	else if(month==2 )
	{
		if(day>=1 && day <=28)
			return 1;
		return 0;
	}
	else if(day >=1 && day<=30)
		return 1;
	return 0;
}

int peace3()
{
	int year=(str[3]-'0')*1000+(str[4]-'0')*100+(str[5]-'0')*10+(str[6]-'0');
	int month=(str[7]-'0')*10+(str[8]-'0');
	int day=(str[9]-'0')*10+(str[10]-'0');
	if(year>=1980 && year<=2016 && month>=1 && month<=12 && day>=1 && peace4(year,month,day))
		return 1;
	return 0;
	
}

int main()
{
	int T,n;
	int a,b,i,j,temp,index;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d%*c",&n,&a,&b);
		temp=n;
		index=0;
		while(temp--)
		{
			scanf("%s",str);
			if(peace1() || peace2() || peace3())
				index++;
		}
		
		printf("%I64d\n",(long long)index*a+(n-index)*b);
		
	}
	
	return 0;
}
