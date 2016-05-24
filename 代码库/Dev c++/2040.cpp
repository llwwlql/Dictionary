#include <stdio.h>
int fun(int n)
{
	int i,j;
	int temp=1;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
			temp=temp+i;
	}
	return temp;
}

int main()
{
	int n;
	int x,y;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&x,&y);
		if(fun(x)==y && fun(y)==x)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
