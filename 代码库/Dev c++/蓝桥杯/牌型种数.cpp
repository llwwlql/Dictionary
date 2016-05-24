#include <stdio.h>
int index=0;
void dfs(int t,int sum)
{
	int i;
	if(sum>13)
		return ;
	if(t==13)
	{
		if(sum==13)
			index++;
		return ;
	}
	for(i=0;i<5;i++)
	{
		dfs(t+1,sum+i);
	}
}

int main()
{
	dfs(0,0);
	printf("%d\n",index);
	return 0;
}
