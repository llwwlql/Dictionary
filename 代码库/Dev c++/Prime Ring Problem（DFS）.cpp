#include <stdio.h>
#include <string.h>
int f[25];
int a[25];
int ans[25];
int n;
void fun()
{
	int i,j;
	for(i=2;i<=25;i++)
	{
		if(f[i]==0)
		{
			for(j=i+i;j<=25;j+=i)
				f[j]=1;
		}
	}	
}

void dfs(int t)
{
	if(t>n)
	{
		if(f[ans[t-1]+1]==0)
		{
			printf("1");
			for(int j=2;j<t;j++)
				printf(" %d",ans[j]);
			putchar('\n');
		}
		return ;
	}
	
	for(int i=2;i<=n;i++)
	{
		if(a[i]==0 && f[i+ans[t-1]]==0)
		{
			a[ans[t-1]]=1;
			ans[t]=i;
			dfs(t+1);
			a[ans[t-1]]=0;
		}
	}
}

int main()
{
	int i,j;
	int T;
	memset(f,0,sizeof(f));
	fun(); 
	T=0;
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
