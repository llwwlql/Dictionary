#include <stdio.h>
#include <string.h>
int a[10005];
int main()
{
	int n,i,j,index;
	memset(a,0,10005);
	a[1]=1;
	for(i=2;i<=10000;i++)
	{
		if(!a[i])
			for(j=i+i;j<=10000;j+=i)
				a[j]=1;
	}
	
	while(scanf("%d",&n),n)
	{
		index=0;
		for(i=2;i<n/2;i++)
		{
			if(!a[i] && !a[n-i])
				index++;
		}
		printf("%d\n",index);
	}
	
	return 0;
}
