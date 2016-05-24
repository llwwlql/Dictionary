#include <stdio.h>
#include <string.h>
int a[20];
int b[10];
int n,sum=0;
void backtrack(int t,int k,int j)
{
	int temp=0,peace,flag=1;
	if(t>9)
		return ;
	if(t<9 && t>(9-j)/2)
	{
		for(int i=j;i<t;i++)
			temp=a[i]+temp*10;
		if(temp%(n-k))
			flag=0;
		else{
			temp=temp/(n-k);
			while(temp)
			{
				peace=temp%10;
				temp/=10;
				if(b[temp])
					flag=0;
			}
		if(flag)
			sum++;
		}
	}
	for(int i=1;i<=9;i++)
	{
		if(!b[i])
		{
			a[t]=i;
			b[i]=1;
			backtrack(t+1,k,j);
			b[i]=0;
		}
		
	}
}

int main()
{
	int temp,index;
	int i,j;
	scanf("%d",&n);
	index=0;
	for(i=1;i<=n;i++)
	{
		j=i;
		index=0;
		while(j)
		{
			temp=j%10;
			j/=10;
			b[temp]=1;
			index++;
		}		
		backtrack(index,i,index);
		memset(b,0,sizeof(b));
	}
	printf("%d\n",sum);
	
	return 0;
}