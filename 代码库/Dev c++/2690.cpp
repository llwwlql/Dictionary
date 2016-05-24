#include <stdio.h>
int main()
{
	int n,T;
	int i,j,a[10005],max,peace;
	scanf("%d",&T);
	while(T--)
	{
		max=-1;
		peace=1;		//作为是否符合要求的标志 
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			if(a[i]>max)
				max=a[i];
		}
		if(n==0 || n==1)
			peace=0;
		
		for(i=1;i<=n && peace;i++)
		{
			if(a[i]!=max && a[i]!=max-1)
				peace=0;
		}
		if(peace)
			printf("%d\n",max);
		else
			printf("Impossible!\n");
	}
	
	return 0;
}
