#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int map[5][5];
int a[20];
int sum=0;

int judge()	//判断最后一列和对角线 
{
	if(map[0][0]+map[1][1]+map[2][2]+map[3][3]==34 && map[0][3]+map[1][2]+map[2][1]+map[3][0]==34 && map[0][3]+map[1][3]+map[2][3]+map[3][3]==34)
		return 1;
	return 0;
}

int judge1(int t)	//判断每一行 
{
	if(map[t][0]+map[t][1]+map[t][2]+map[t][3]==34)
		return 1;
	return 0;
}

int judge2(int t)	//判断每一列
{
	if(map[0][t]+map[1][t]+map[2][t]+map[3][t]==34)
		return 1;
	return 0;
}

void dfs(int t)
{
	if(t%4==0)
	{
		if(!judge1(t/4-1))
		{
			return ;
		}
	}
	
	if(t/4==3 && t%4==1)
	{
		if(!judge2(t%4-1))
		{
			return ;
		}	
	}
	
	if(t==16)
	{
		if(judge())
			sum++;

		return ;
	}
	
	for(int i=2;i<=16;i++)
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
	int n,m;
	memset(a,0,sizeof(a));
	a[1]=1;
	map[0][0]=1;
	dfs(1);
	printf("%d\n",sum);
	
	return 0;
}
