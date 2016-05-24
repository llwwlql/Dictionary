#include <stdio.h>
int main()
{
	int i,j;
	for(i=1;i<=46;i++)
	{
		for(j=i+2;j<=48;j++)
		{
			if(1225-i-i-1-j-j-1+(i*(i+1))+(j*(j+1))==2015)
				printf("%d\n",i);
		}
	}
	
	return 0;
}
