#include <stdio.h>
#include <string.h> 
int main()
{
	int a[100005];
	int mod,step;
	int temp,index;
	int i;
	while(~scanf("%d %d",&step,&mod))
	{
		memset(a,0,sizeof(a));
		
		temp=0;
		a[0]=0;
		index=1;
		while(1)
		{
			temp=(temp+step)%mod;
			if(a[temp])
				break;
			a[temp]=1;
			index++;
		}
		
		printf("%10d%10d    ",step,mod);
		
		if(index>=mod)
			printf("Good Choice\n\n");
		else
			printf("Bad Choice\n\n");
	}
	
	return 0;
}
