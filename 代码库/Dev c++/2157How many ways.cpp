#include <stdio.h>
#include <string.h>
typedef struct{
	int graph[25][25];
}Mod;
int n;

Mod mlt(Mod a,Mod b,int p)
{
	int i,j,k;
	Mod c;
	memset(c.graph,0,sizeof(c.graph));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				c.graph[i][j]=(c.graph[i][j]+a.graph[i][k]*b.graph[k][j])%p;
			}
		}
	}
	return c;
}

Mod PowerMod(Mod a,int b,int p)
{
	int i,j;
	Mod c;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			c.graph[i][j]= (i==j);
	while(b>0)
	{
		if(b%2)
			c=mlt(c,a,p);
		b/=2;
		a=mlt(a,a,p);
	}
	return c;
}

int main()
{
	int m,i,j;
	int a,b,k,t;
	Mod c,temp;
	
	while(scanf("%d %d",&n,&m),n||m)
	{
		memset(c.graph,0,sizeof(c.graph));
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			c.graph[a][b]=1;
		}
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d %d %d",&a,&b,&k);
			temp=PowerMod(c,k,1000);
			printf("%d\n",temp.graph[a][b]);
		}		
	}
	
	return 0;
}
