#include <stdio.h>
#include <string.h>
#include <math.h>
int a[10];
int map[4][5];
int sum=0;

int judge()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(fabs(map[i][j]-map[i][j+1])==1||fabs(map[i][j]-map[i+1][j+1])==1||fabs(map[i][j]-map[i+1][j-1])==1||fabs(map[i][j]-map[i+1][j])==1)
				return 0;
		}
	}
	return 1;
}

void dfs(int t)
{
	if(t==11)
	{
		if(judge())
			sum++;
		return ;
	}
	for(int i=0;i<10;i++)
	{
		if(!a[i])
		{
			a[i]=1;
			map[t/4][t%4]=i;
			dfs(t+1);
			a[i]=0;
		}
	}
}

int main()
{
	int i,j;
	memset(a,0,sizeof(a));
	map[0][0]=10000;
	map[2][3]=10000;
	for(i=0;i<4;i++)
		map[i][4]=10000;
	for(i=0;i<5;i++)
		map[3][i]=10000;
	dfs(1);
	printf("%d\n",sum);
	
	return 0;
}
