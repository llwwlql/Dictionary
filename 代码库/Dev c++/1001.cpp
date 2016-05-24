#include <stdio.h>
int main()
{
	int x,y,w,n;
	int i;
	int sum,index;
	while(~scanf("%d %d %d %d",&x,&y,&w,&n))
	{
		sum=0;
		index=x;
		for(i=1;i<n;i++)
		{
			if(w<=index)
			{
				sum+=w;
				index=index-w;
			}
			else
			{
				sum+=(index+y);
				index=x;
			}
			
		}
		printf("%d\n",sum);
	}
	return 0;
}
