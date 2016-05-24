#include <stdio.h>
#include <math.h>
int main()
{
	int N,n,m;
	int i,j,index,k;
	int temp;
	int flag=0;
	scanf("%d",&N);
	while(N--)
	{
		flag=0;
		while(scanf("%d %d",&n,&m),n||m)
		{
			flag++;
			index=0;
			for(i=1;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if((i*i+j*j+m)%(i*j)==0)
						index++;
				}
			}
			printf("Case %d: %d\n",flag,index);
		}
		if(N)
			putchar('\n');
	}
	return 0;
}
