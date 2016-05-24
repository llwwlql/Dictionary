#include <stdio.h>
#include <math.h>
int main()
{
	int n,m;
	int i,a,b,index;
	while(~scanf("%d %d",&n,&m))
	{
		int temp=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			index=fabs(b-a)-1;
			temp=temp^index;
		}
		if(temp)
			printf("I WIN!\n");
		else
			printf("BAD LUCK!\n");
	}
	return 0;
}
