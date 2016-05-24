#include <stdio.h>
#include <string.h>
int pre[1005];
int n,m;
int find(int x)
{
	int r=x;
	while(pre[r]!=r)
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

void join(int a,int b)
{
	int fx=find(a),fy=find(b);
	if(fx!=fy)
		pre[fx]=fy;
}
int main()
{
	int T,index;
	int t[1005];
	int i,j,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			pre[i]=i;
		
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			join(a,b);
		}
		memset(t,0,sizeof(t));
		for(i=1;i<=n;i++)
		{
			t[pre[i]]=1;
		}
		index=0;
		for(i=1;i<=n;i++)
			printf("%d ",t[i]);
			/*if(t[i])
				index++;*/
		printf("%d\n",index-1);
	}
	
	return 0;
}
