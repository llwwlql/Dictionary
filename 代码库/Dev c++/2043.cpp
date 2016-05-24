#include <stdio.h>
#include <string.h>
int main()
{
	char a[55];
	int m,i,j;
	int peace,index[5],sum;
	scanf("%d",&m);
	while(m--)
	{
		peace=sum=0;
		index[1]=index[2]=index[3]=index[4]=0;
		scanf("%s",a);
		if(strlen(a)>=8 && strlen(a)<=16)
		{
			for(i=0;i<strlen(a);i++)
			{
				if(a[i]>='A' && a[i]<='Z')
					index[1]=1;
				if(a[i]>='a' && a[i]<='z')
					index[2]=1;
				if(a[i]>='0' && a[i]<='9')
					index[3]=1;
				if(a[i]=='~' || a[i]=='!' ||a[i]=='@' || a[i]=='#' || a[i]=='$' ||a[i]=='%' ||a[i]=='^')
					index[4]=1;
			}
			for(i=1;i<=4;i++)
			{
				sum+=index[i];
			}
			if(sum>=3)
				peace=1;
		}
		if(peace)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	
	return 0;
}
