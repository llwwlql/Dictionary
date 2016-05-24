#include <stdio.h>
int main()
{
	int n,i,j;
	int a,index;
	int max;
	scanf("%d",&n);
	scanf("%d",&a);
	max=a;
	index=0;
	for(i=1;i<n;i++)
	{
		scanf("%d",&a);
		if(a>max)
		{
			max=a;
			index=i;
		}
	}
	printf("%d %d\n",max,index);
	return 0;
}
