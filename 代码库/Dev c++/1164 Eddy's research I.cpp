#include <stdio.h>
#include <string.h>
int a[100000];
int fun()
{
	int i,j;
	memset(a,0,sizeof(a));
	for(i=2;i<=65535;i++)
	{
		if(!a[i])
			for(j=i+i;j<=65535;j+=i)
				a[j]=1;
	}
	
}

int main()
{
	int n,i,peace;
	fun();
	while(~scanf("%d",&n))
	{
		peace=1;
		i=2;
		while(n)
		{
			if(n%i==0 && !a[i])
			{
				if(peace)
				{
					peace=0;
					printf("%d",i);
				}
				else
					printf("*%d",i);
			}
			n/=i;
		}
		putchar('\n');
	}
	return 0;
}
