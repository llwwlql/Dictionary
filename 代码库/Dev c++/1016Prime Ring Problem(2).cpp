#include <stdio.h>
#include <string.h>
int ans[25];
int a[25];
int n;
int f[35];

void fun()
{
	int i,j;
	memset(f,0,sizeof(f));
	
	for(i=2;i<=30;i++)
	{
		for(j=2*i;j<=30;j+=i)
			f[j]=1;
	}
}

void dfs(int t)
{
	int i;
	if(t>n)
	{
		if(f[ans[n]+1]==0)
		{
			printf("1");
			for(i=2;i<=n;i++)
				printf(" %d",ans[i]);
			putchar('\n');
		}
		return ;
	}
	
	for(i=2;i<=n;i++)
	{
		if(a[i]==0 && f[ans[t-1]+i]==0)
		{
			a[i]=1;
			ans[t]=i;
			dfs(t+1);
			a[i]=0;
		}
	}
}

int main()
{
	int T=0;
	fun();
	while(~scanf("%d",&n))
	{
		T++;
		printf("Case %d:\n",T);
		memset(a,0,sizeof(a));
		
		a[1]=1;
		ans[1]=1;		
		dfs(2);
		putchar('\n');
	}
	
	return 0;
}
