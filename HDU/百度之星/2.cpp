#include <stdio.h>
int pre[100005];
int find(int x)
{//找到前驱 
	int r=x;
	while(r!=pre[r])
		r=pre[r];
	int i=x,j;
	while(i!=r)
	{//更新该连通集合里前驱不为r的点
		j=pre[i]; pre[i]=r; i=j;
	}
	return r;
}

int main()
{
	int T;
	int n,m,i,j;
	int a,b;
	scanf("%d",&T);
	while(T--)
	{
		long long sum=0;
		for(i=1;i<100005;i++)
			pre[i]=i;
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			if(pre[a]<pre[b])
			{
				pre[b]=a;
				find(b);
			}
		}
		for(i=n;i>=1;i--)
			sum+=pre[i];
		printf("%I64d\n",sum);
	}
	
	return 0;
}
