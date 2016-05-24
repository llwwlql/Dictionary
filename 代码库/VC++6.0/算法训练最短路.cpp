#include <stdio.h>
typedef struct G{
	int vex,arc;
	int V[105][105];
}Graph;

int main()
{
	Graph g;
	int a,b,c;
	int i,j,k;
	scanf("%d %d",&g.vex,&g.arc);
	for(i=0;i<=g.vex;i++)
	{
		for(j=0;j<=g.vex;j++)
			g.V[i][j]=1000000;
	}	
	for(i=1;i<=g.arc;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		g.V[a][b]=c;
	}
	for(k=1;k<=g.vex;k++)
	{
		for(i=1;i<=g.vex;i++)
		{
			for(j=1;j<=g.vex;j++)
			{
				if(g.V[i][j]>g.V[i][k]+g.V[k][j])
					g.V[i][j]=g.V[i][k]+g.V[k][j];
			}
		}
	}
	
	for(i=2;i<=g.vex;i++)
		printf("%d\n",g.V[1][i]);
	
	return 0;
}