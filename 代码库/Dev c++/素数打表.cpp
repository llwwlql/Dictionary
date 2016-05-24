#include <stdio.h>
#include <string.h>
int a[200005];
int main()
{
	int i,j,n;
	memset(a,0,sizeof(a));
	for(i=2;i<=200000;i++)
	{
		if(!a[i])
		for(j=i+i;j<=200000;j+=i)
			a[j]=1;
	}
	
	scanf("%d",&n);
	
	for(i=2;i<=n;i++)
		if(!a[i])
			printf("%d ",i);
	
	return 0;
}

