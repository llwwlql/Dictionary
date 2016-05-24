#include <stdio.h>
int main()
{
	int year,month,day;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int peace=0;
		scanf("%d %d %d",&year,&month,&day);
		if((month+day)%2==0|| month==9 && day==30 || month==11 && day==30)
			peace=1;
		if(peace)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
