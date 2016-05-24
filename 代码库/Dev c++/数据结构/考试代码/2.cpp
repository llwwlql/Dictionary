#include <stdio.h>
int gcd(int n,int m)
{
	if(n%m==0)
		return m;
	return gcd(m,n%m);
}

int main()
{
	int n,m,temp;
	scanf("%d %d",&n,&m);
	printf("%d",gcd(n,m));
	return 0;
}
