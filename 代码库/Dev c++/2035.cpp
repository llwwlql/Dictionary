#include <stdio.h>
int main()
{
	int n,m;
	int index;
	int i,j;
	while(~scanf("%d %d",&n,&m),n||m)
	{
		index=n;
		for(i=1;i<m;i++)
			index=(index*n)%1000;
		printf("%d\n",index);
	}
	
	return 0;
}
