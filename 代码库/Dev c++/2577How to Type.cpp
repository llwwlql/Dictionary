#include <stdio.h>
#include <string.h>
int dpa[105],dpb[105];

int min(int a,int b)
{
	return a>b? b:a;
}

int main()
{
	int T;
	int i,j,len;
	char str[105];
	scanf("%d%*c",&T);
	while(T--)
	{
		scanf("%s",str+1);
		dpa[0]=0;	//µÆ¹Ø 
		dpb[0]=1;	//µÆ¿ª 
		for(i=1;str[i];i++)
		{
			if(str[i]>='a' && str[i]<='z')
			{
				dpa[i]=min(dpa[i-1]+1,dpb[i-1]+2);
				dpb[i]=min(dpa[i-1]+2,dpb[i-1]+2);
			}
			else
			{
				dpa[i]=min(dpa[i-1]+2,dpb[i-1]+2);
				dpb[i]=min(dpa[i-1]+2,dpb[i-1]+1);
			}
		}
		printf("%d\n",min(dpa[i-1],dpb[i-1]+1));
	}
	
	
	return 0;
}
