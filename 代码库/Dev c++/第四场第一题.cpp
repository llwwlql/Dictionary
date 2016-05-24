#include <stdio.h>
#include <math.h>
int main()
{
	int T;
	int w[2],x[2],y[2],z[2];
	int index1,index2;
	int temp1,temp2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d %d %d %d %d",&w[0],&x[0],&y[0],&z[0],&w[1],&x[1],&y[1],&z[1]);
		index1=w[0]*w[1];
		index2=x[0]*x[1];
		while(y[0] || z[0])
		{
			if(index1>index2)
			{
				if(fabs(temp1-index2+y[1])>fabs(index1-index2+z[1]) && z[0])
				{
					temp2+=z[1];
					z[0]--;
				}
				else if(y[0])
				{
					temp2+=y[1];
					y[0]--;
				}
				else
				{
					temp2+=z[1];
					z[0]--;
					
				}
			}
			else
			{
				if(fabs(temp2-index1+y[1])>fabs(index2-index1+z[1]) && z[0])
				{
					temp1+=z[1];
					z[0]--;
				}
				else if(y[0])
				{
					temp1+=y[1];
					y[0]--;
				}
				else
				{
					temp1+=z[1];
					z[0]--;
				}
			}
		}
		
		printf("%d\n",index1>index2? index1:index2);
		
	}
	
	return 0;
}
