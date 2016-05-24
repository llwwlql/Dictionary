#include <stdio.h>
#include <string.h>
int a[15];
int b[1000005];
int pre[20][20];
int judge(int i)
{
	if(a[pre[b[i]][b[i-1]]]==0 && pre[b[i]][b[i-1]]!=0)
		return 1;
	return 0;	
}

int main()
{
	int i,j;
	int T,n,peace;
	scanf("%d",&T);
	memset(pre,0,sizeof(pre));
	pre[1][3]=2;
	pre[3][1]=2;
	
	pre[1][7]=4;
	pre[7][1]=4;
	
	pre[9][1]=5;
	pre[1][9]=5;
	
	pre[4][6]=5;
	pre[6][4]=5;
	
	pre[7][9]=8;
	pre[9][7]=8;
	
	pre[7][3]=5;
	pre[3][7]=5;
	
	pre[9][3]=6;
	pre[3][9]=6;
	
	pre[2][8]=5;
	pre[8][2]=5;
	
	
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		memset(a,0,sizeof(a));
		
		a[b[1]]=1;
		peace=1;
		for(i=2;i<=n;i++)
		{
			a[b[i]]=1;
			if(judge(i))
			{
				peace=0;
				break;
			}
		}
		if(peace)
			printf("valid\n");
		else
			printf("invalid\n");
	}
	
	return 0;
}
