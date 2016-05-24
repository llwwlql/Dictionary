#include <stdio.h>
int main()
{
	int x1,x2,y1,y2,z1,z2;
	while(~scanf("%d %d %d %d %d %d",&x1,&x2,&y1,&y2,&z1,&z2))
	{
		if((x1*y2-x2*y1)+(z1*x2-z2*x1)+(y1*z2-y2*z1)==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
