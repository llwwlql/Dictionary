#include <stdio.h>
int pre[1005];
int find(int x)
{
	int r=x;
	while(r!=pre[r])
		r=pre[r];
	int i=x,j;
	while(i!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	
	return r;
}

void Merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
		pre[fx]=fy;	
}

int main()
{
	int T;
	int n,m,i,j,a,b;
	scanf("%d",&T);
	while(T--)
	{
		int index=0;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			pre[i]=i;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			Merge(a,b);
		}
		for(i=1;i<=n;i++)
			if(pre[i]==i)
				index++;
		printf("%d\n",index);
	}
	
	return 0;
}
