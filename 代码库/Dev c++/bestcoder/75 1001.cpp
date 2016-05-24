#include <stdio.h>
int main()
{
	int T;
	int n,m;
	int index,temp;
	scanf("%d",&T);
	while(T--)
	{
		index=0;
		scanf("%d %d",&n,&m);
		if(n<m)
		{
			temp=n;
			n=m;
			m=temp;
		}
		do
		{
			index+=n/m;
			temp=m;
			m=n%m;
			n=temp;
		}while(m);
		printf("%d\n",index);
	}
	
	return 0;
}
