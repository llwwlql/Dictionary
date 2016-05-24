#include <stdio.h>
int main()
{
	int i;
	int sum=0,temp=0;
	for(i=1;i<=30;i++)
	{
		temp=i*i;
		sum+=temp;
	}
	
	printf("%d\n",sum);
	
	return 0;
}
