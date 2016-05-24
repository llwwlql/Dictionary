#include <stdio.h>
int main()
{
	int n;
	int a,b;
	int i,j;
	int temp[55];
	temp[1]=temp[2]=1;
	for(i=3;i<=50;i++)
		temp[i]=temp[i-1]+temp[i-2];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",temp[b-a+1]);
	}
	
	return 0;
}
