#include <stdio.h>
int main()
{
	int fi[1000];
	int i,j,n,peace;
	fi[0]=fi[1]=1;
	for(i=2;i<=100;i++)
		fi[i]=fi[i-1]+fi[i-2];
	while(scanf("%d",&n),n)
	{
		peace=0;
		for(i=1;n>fi[i-1] && !peace;i++)
			if(n==fi[i])
				peace=1;
		if(peace)
			printf("Second win\n");
		else
			printf("First win\n");
	}	
		
	return 0;
}
