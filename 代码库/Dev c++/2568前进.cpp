#include <stdio.h>
int main()
{
	int T;
	int n,ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		while(n>0)
		{
			if(n%2)
				ans++;
			n/=2;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
