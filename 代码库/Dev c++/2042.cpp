#include <stdio.h>
int main()
{
	int n,m,i,j;
	int num;
	scanf("%d",&n);
	while(n--)
	{
		num=3;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			num=(num-1)*2;
		}
		printf("%d\n",num);
	}
	
	return 0;
}
