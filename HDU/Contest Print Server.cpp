#include <stdio.h>
int main()
{
	int T;
	int n,s,x,y,mod,temp,count;
	int i,j,p;
	char str[25];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d %d",&n,&s,&x,&y,&mod);
		count=s;
		for(i=1;i<=n;i++)
		{
			if(temp)
				scanf("%s request %d pages",str,&p);
			temp=1;
			if(count>=p)
			{
				printf("%d pages for %s\n",p,str);
				count-=p;
			}
			else
			{
				printf("%d pages for %s\n",count,str);
				s=(s*x+y)%mod;
				count=s;
				temp=0;
				i--;
			}
		}
        printf("\n");
	}
	return 0;
}
