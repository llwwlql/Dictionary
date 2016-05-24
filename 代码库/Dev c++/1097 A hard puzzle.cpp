#include <stdio.h>
int a[10];
int main()
{
	int x,y,i;
	while(~scanf("%d %d",&x,&y))
	{
		x=x%10;
		i=0;
		a[0]=x;
		do
		{
			i++;
			a[i]=(a[i-1]*x)%10;
		}while(a[i]!=x);
		
		printf("%d\n",a[(y-1)%i]);
	}
	return 0;
}
