#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	int i,j,index;
	int a[100005];
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		index=0;
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j+=i)
				a[j]=(a[j]+1)%2;
		}
		
		printf("%d\n",a[n]);
		
	}
	
	return 0;
}
