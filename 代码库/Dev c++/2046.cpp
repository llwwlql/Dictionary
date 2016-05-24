#include <stdio.h>
int main()
{
	int n;
	int i;
	long long fibe[51];
	fibe[0]=fibe[1]=1;
	for(i=2;i<=50;i++)
		fibe[i]=fibe[i-1]+fibe[i-2];
	while(~scanf("%d",&n))
		printf("%I64d\n",fibe[n]);
	
	return 0;
}
