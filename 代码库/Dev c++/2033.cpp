#include <stdio.h>
int main()
{
	int a[5],b[5];
	int n,peace1,peace2;
	scanf("%d",&n);
	while(n--)
	{
		peace1=peace2=0;
		scanf("%d %d %d %d %d %d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
		if(a[2]+b[2]>60)
			peace1=1;
		a[2]=(a[2]+b[2])%60;
		if(a[1]+b[1]+peace1>60)
			peace2=1;
		a[1]=(a[1]+b[1]+peace2)%60;
		a[0]=a[0]+b[0]+peace2;
		printf("%d %d %d\n",a[0],a[1],a[2]);
	}
	
	return 0;
}
