#include <stdio.h>
#include <string.h>
int n;
int b[10];
int a[10];
int sum=0;

int judge(int t,int num,int k)
{
	int i,j,peace,index;
	int ans[10];
	int temp,flag1,flag2;
	temp=0;
	
	for(i=0;i<=9;i++)
		ans[i]=b[i];
	
	for(i=0;i<t;i++)
		temp=temp*10+a[i];
	flag1=temp;
		
	temp=num*temp;
	
	flag2=temp;
	index=0;
	while(temp)
	{
		peace=temp%10;
		temp/=10;
		if(ans[peace])
			return 0;
		index++;
		ans[peace]=1;
	}
	
	if(index+t==k)
		return 1;
	
	return 0;
}

void dfs(int t,int num,int k)
{
	int i;

	if(judge(t,num,k))
		sum++;
	if(t<=k/2)
	{
		for(i=1;i<=9;i++)
		{
			if(!b[i])
			{
				b[i]=1;
				a[t]=i;
				dfs(t+1,num,k);
				b[i]=0;
			}
		}
	}
}

int main()
{
	int j,temp,index,i,peace;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		b[0]=1;
		j=i;
		index=0;
		peace=0;
		while(j)
		{
			temp=j%10;
			j/=10;
			if(b[temp])
			{
				peace=1;
				break;
			}
			b[temp]=1;
			index++;
		}
		if(peace)
			continue;
		dfs(0,n-i,9-index);
	}
	printf("%d\n",sum);
	
	return 0;
}
