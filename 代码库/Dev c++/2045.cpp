#include <stdio.h>
int main()
{
	int n;
	long long temp[51];
	temp[1]=3;
	temp[2]=6;
	temp[3]=6;
	int i;
	for(i=4;i<=50;i++)
		temp[i]=temp[i-1]+2*temp[i-2];
	while(~scanf("%d",&n))
		printf("%I64d\n",temp[n]);
	
	return 0;
}
