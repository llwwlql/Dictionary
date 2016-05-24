#include <stdio.h>
#include <string.h>
int a[10];
int main()
{
	int i;
	int T,peace=0;
	long long n,temp;
	int str[20];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d",&n);
		memset(str,0,sizeof(str));
		temp=n;
		int k=0;
		while(temp)
		{
			str[k++]=temp%10;
			temp/=10;		
		}
		
		if(k%2)
		{
			str[k++]=4;
		}
		int f=1,s=0;
		int aver=k/2;
		
		for(int i=0;i<k;i++)
		{
			if(str[i]>4 && str[i]<7)
			{
				if(s<aver)
				{
					str[i]=7;
					s++;
				}
				else
				{
					str[i]=4;
					int j=i;
					peace=1;
					f++;
					while(peace)
					{
						peace=(str[j+1]+peace)/10;
						str[j+1]=(str[j+1]+peace)%10;
					}
				}
			}
			else if(str[i]>=0 && str[i]<4)
			{
				if(f<aver)
				{
					str[i]=4;
					f++;
				}
				else
				{
					str[i]=7;
					int j=i;
					peace=1;
					s++;
					while(peace)
					{
						peace=(str[j+1]+peace)/10;
						str[j+1]=(str[j+1]+peace)%10;
					}
				}
			}
			else if(str[i]>7)
			{
				if(f<aver)
				{
					str[i]=4;
					f++;
				}
				else
				{
					str[i]=7;
					s++;
				}
				int j=i;
				peace=1;
				while(peace)
				{
					peace=(str[j+1]+peace)/10;
					str[j+1]=(str[j+1]+peace)%10;
				}
			}
		}
		for(i=k-1;i>=0;i--)
			printf("%d",str[i]);
		putchar('\n');
	}
	
	return 0;
}
