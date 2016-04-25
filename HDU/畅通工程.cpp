#include <stdio.h>
#include <string.h>
int map[1005][1005];
int pre[1005];

int find(int x)
{
	int r=x;
	while(pre[r]!=r)
		r=pre[r];
	int i,j; 
		
	return r;
}

void Link(int a,int b)
{
	int fx=find(a),fy=find(b);
	
	if(fx!=fy)
		pre[fx]=fy;
}

int main()
{
	int n,m;
	int i,j,index;
	int a,b;
	while(scanf("%d %d",&n,&m),n)
	{
		for(i=1;i<=n;i++)
			pre[i]=i;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			Link(a,b);
		}
		index=0;
		for(i=1;i<=n;i++)
			if(pre[i]==i)
				index++;
		printf("%d\n",index-1);
	}
	
	return 0;
}
