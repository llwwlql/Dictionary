#include <stdio.h>
int main()
{
	int T,n;
	float average;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		average=100.0/n;
		printf("%.2f%%\n",average);
	}
	
	return 0;
}
