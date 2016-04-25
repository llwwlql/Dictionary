#include <stdio.h>
int main()
{
	int i,j;
	int peace=0; 
	for(i=1;i<=100 && !peace;i++)
	{
		for(j=1;j<=100;j++)
		{
			if(i+3*j==105)
			{
				printf("%d %d\n",i,j);
				peace=1;
				break;
			}
		}
	}
	
	printf("%d\n",i+j+315-7*j-3*i);
	
	return 0;
}
