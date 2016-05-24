#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int T;
	int i,j;
	char ch,temp[105]; 
	while(scanf("%d%*c",&T),T)
	{
		char str[2][10];
		int index[2]={0};
		memset(str,0,sizeof(str));
		int sum[2]={0};
		for(i=0;i<T;i++)
		{	
			gets(temp);
			int len=strlen(temp);			
			
			
			if(temp[len-5]==' ' && temp[len-6]=='o' && temp[len-7]=='n' && temp[len-8]==' ')
			{
				str[i%2][index[i%2]++]='X';	
			}
			else
			{
				sum[i%2]++;
				str[i%2][index[i%2]++]='O';
			}
					
		}
		if(T%2==1)
			str[1][index[1]++]='-';
		for(i=1;i<=(T+1)/2;i++)
			printf("%d ",i);
		printf("Score\n");
		for(i=0;i<2;i++)
		{
			for(j=0;j<(T+1)/2;j++)
				printf("%c ",str[i][j]);
			printf("%d\n",sum[i]);
		}
	}	
	
	return 0;
}
