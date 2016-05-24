#include <stdio.h>
int main()
{
	int n;
	int i;
	char a;
	int index;
	while(~scanf("%d",&n))
	{
		getchar();
		for(i=0;i<n;i++)
		{
			index=0;
			while(scanf("%c",&a),a!='\n')
			{
				if(a>='0' && a<='9')
					index++;
			}
			printf("%d\n",index);
		}
	}
	
	return 0;
}
