#include <stdio.h>
#include <string.h>
#define MAX 1000005
int a[MAX];
int main()
{
	int T;
	int n,i,j,d;
	char ch;
	scanf("%d%*c",&T);
	while(T--)
	{
		int min=MAX;
		int count=0;
		memset(a,0,sizeof(a));
		scanf("%d%*c",&n);
		for(i=0;i<n;i++)
		{
			scanf("%c%*c",&ch);
			if(ch=='b')
			{
				scanf("%d%*c",&d);
				a[d]++;
				if(count<d)
					count=d;
				if(min==d && a[d]!=1)
					min=MAX;
				if(a[d]==1)
				{
					if(d<min)
					{
						min=d;
					}
				}
			}
			else if(ch=='c')
			{
				scanf("%d%*c",&d);
				a[d]--;
				if(min==d && a[d]!=1)
					min=MAX;
				if(a[d]==1 && min>d)
					min=d;
			}
			else if(ch=='q')
			{			
			
				if(min==MAX)
				{
					for(j=1;j<=count;j++)
					{
						if(a[j]==1)
						{
							min=j;
							break;
						}
					}
				}	
				if(min==MAX)
					printf("none\n");
				else
					printf("%d\n",min);
			}
		}
	}
	
	return 0;
}
