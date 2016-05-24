#include <stdio.h>
int main()
{
	int i,j;
	int n;
	int a;
	long long temp[41];
	temp[0]=temp[1]=1;
	for(i=2;i<=40;i++)
		temp[i]=temp[i-1]+temp[i-2];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		printf("%I64d\n",temp[a-1]);
	}
	
	return 0;
}
