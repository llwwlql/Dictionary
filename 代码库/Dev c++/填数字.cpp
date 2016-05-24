//将1到20排一列，要求每相邻两位数的和是质数，试求排列的种数。
#include <stdio.h>
int main()
{
	int i,j,k;
	for(i=2;i<=12;i++)
	{
		if(i!=3 && i!=8)
		for(j=2;j<=12;j++)
		{
			if(j!=3 && j!=8)
			for(k=2;k<=12;k++)
			{
				if(k!=3 && k!=8)
				if(i!=j && j!=k && i!=k)
				{
					if(i+j-k==10)
						printf("%d %d %d\n",i,j,k);
				}
			}
		}
	}
	return 0;
}
