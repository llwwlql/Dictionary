#include <stdio.h>
int sum=0;
void dfs(int flower,int shop,int t)
{
	if(flower<0 || shop<0 || t<=0)
		return ;
	if(flower==0 && shop==0 && t==1)
		sum++;
	dfs(flower-1,shop,t-1);
	dfs(flower,shop-1,t*2);
}
int main()
{
	dfs(9,5,2);
	printf("%d\n",sum);
	return 0;
}
