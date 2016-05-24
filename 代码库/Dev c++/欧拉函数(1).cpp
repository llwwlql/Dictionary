#include <stdio.h>

int euler(int n)
{
	int ans=1,i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			n/=i;
			ans*=i-1;
			while(n%i==0)
			{
				n/=i;
				ans*=i;
			}
		}
	}
	if(n>1)
		ans*=n-1;
	return ans;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	printf("%d\n",euler(n));
	
	return 0;
}
