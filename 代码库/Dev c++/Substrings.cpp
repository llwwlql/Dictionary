#include <stdio.h>
#include <string.h>
int main()
{
	int T,n,i;
	char str[105];
	int max,index;
	scanf("%d%*c",&T);
	while(T--)
	{
		max=0;
		index=0;
		scanf("%d%*c",&n);
		for(i=1;i<=n;i++)
		{
			memset(str,0,105);
			scanf("%s",str);
			if(strlen(str)>max)
			{
				max=strlen(str);
				index=i;
			}
		}
		printf("%d\n",index);
	}
	
	return 0;
}
