#include <stdio.h>
int main()
{
	int T;
	int n,index,a,b;
	int temp;
	scanf("%d",&T);
	while(T--)
	{
		index=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d %d",&a,&b);
			if(b%64)
				index+=b/64+1;
			else
				index+=b/64;
		}
		if(index%36)
			temp=1;
		else
			temp=0;
		printf("%d\n",index/36+temp);	
	}
	
	return 0;
}
