#include <stdio.h>
int main()
{
	int T;
	int month,day;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&month,&day);
		if(month>10 || month==10 && day>21)
			printf("What a pity, it has passed!\n");
		else if(month==10 && day==21)
			printf("It's today!!\n");
		else
		{
			int sum=0;
			switch(month)
			{
				case 10:sum+=30;
				case 9:sum+=31;
				case 8:sum+=31;
				case 7:sum+=30;
				case 6:sum+=31;
				case 5:sum+=30;
				case 4:sum+=31;
				case 3:sum+=28;
				case 2:sum+=31;
				case 1:sum+=day;
			}
			printf("%d\n",294-sum);
		}
	
	}
	
	return 0;
}
