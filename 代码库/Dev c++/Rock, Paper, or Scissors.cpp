#include <stdio.h>
int main()
{
	int T,n;
	int i,j,index1,index2;
	char ch1,ch2;
	scanf("%d%*c",&T);
	while(T--)
	{
		scanf("%d%*c",&n);
		index1=index2=0;
		for(i=1;i<=n;i++)
		{
			scanf("%c %c%*c",&ch1,&ch2);
			if(ch1=='R' && ch2=='S' || ch1=='S' && ch2=='P' || ch1=='P' && ch2=='R')
				index1++;
			else if(ch1=='R' && ch2=='R' || ch1=='S' && ch2=='S' || ch1=='P' && ch2=='P')
				index2++;
		}
		if(index1*2>n-index2)
			printf("Player 1\n");
		else if(index1*2<n-index2)
			printf("Player 2\n");
		else
			printf("TIE\n");
	}
	
	return 0;
}
