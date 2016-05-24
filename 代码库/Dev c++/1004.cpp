#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j,index,peace,max;
	char str[1005][20];
	char temp[20];
	while(scanf("%d",&n),n)
	{
		memset(str,0,sizeof(str));
		for(i=0;i<n;i++)
			scanf("%s%*c",str[i]);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(strcmp(str[i],str[j])<0)
				{
					strcpy(temp,str[i]);
					strcpy(str[i],str[j]);
					strcpy(str[j],temp);
				}
			}
		}
		index=1;
		max=1;
		peace=0;
		for(i=1;i<n;i++)
		{
			if(strcmp(str[i],str[i-1])==0)
				index++;
			else
				index=1;
			if(index>max)
			{
				max=index;
				peace=i;
			}
		}
		printf("%s\n",str[peace]);
	}
	return 0;
}
