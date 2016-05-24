#include <stdio.h>
int a[1000005];
int main()
{
	int T,i; 
	int n,max=0,index1=0,index2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		a[n]++;
		if(n>max)
			max=n;
	}
	for(i=0;i<=max;i++)
		if(a[i]>index1)
		{
			index1=a[i];
			index2=i;
		}
		
	printf("%d\n",index2);
	
	return 0;
}
