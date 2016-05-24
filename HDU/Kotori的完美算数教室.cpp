#include <stdio.h>
int main()
{
	int a[105];
	int n;
	int i;
	a[0]=1;
	for(i=1;i<=30;i++)
	{
		a[i]=a[i-1]*i; 
		printf("case :%d %I64d \n",i,a[i]%2016);
	}
	/*while(~scanf("%d",&n))
	{
		
		
	}*/
	
	return 0;
}
