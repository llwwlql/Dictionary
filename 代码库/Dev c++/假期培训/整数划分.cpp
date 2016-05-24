#include <stdio.h>
int fun(int n,int m)
{
	if(m==1)
		return 1;
	else if(m>n)
		return fun(n,n);
	else if(m==n)
		return 1+fun(n,n-1);
	else
		return fun(n,m-1)+fun(n-m,m);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",fun(n,n));
	return 0;
}
