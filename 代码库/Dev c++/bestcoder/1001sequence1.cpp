#include <stdio.h>
#include <math.h>
int main()
{
	int n,b,c;
	int a[105];
	int i,j;
	while(~scanf("%d %d %d",&n,&b,&c))
	{
		int index=0;
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if((int)fabs(a[i]-a[j])%b==c)
					index++;
			}
		}
		printf("%d\n",index);
	}
	
	return 0;
}
