#include <stdio.h>
int main()
{
	long n;
	int m;
	char a[100];
	int temp,peace,i;
	while(~scanf("%ld %d",&n,&m))
	{
		peace=0;
		if(n<0)
		{
			peace=1;
			n=-n;
		}
		for(i=0;n;i++)
		{
			temp=n%m;
			if(temp>=10)
				a[i]=temp-10+'A';
			else
				a[i]=temp+'0';
			n/=m;
		}
		if(peace)
			printf("-");
		for(i=i-1;i>=0;i--)
			printf("%c",a[i]);
		putchar('\n');
		
	}
	
	return 0;
}
