#include <stdio.h>
#include <math.h>
#include <string.h>
int a[15];
int b[15],c[15];
int max;
void dfs(int t,int n)
{
	int i,j;
	if(t==n+1)
	{
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
			if(fabs(b[i]-b[j])==fabs(i-j))
				return ;
		max++;
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(!c[i])
		{
			c[i]=1;
			b[t]=i;
			dfs(t+1,n);
			c[i]=0;
		}
	}
}

int main()
{
	int i,j;
	int n;
	memset(a,0,sizeof(a));
	a[1]=1;
	for(i=5;i<=5;i++)
	{
		max=0;
		memset(c,0,sizeof(c));
		dfs(1,i);
		a[i]=max;
	}
	
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	
	/*while(scanf("%d",&n),n)
		printf("%d\n",a[n]);
	*/
	return 0;
}