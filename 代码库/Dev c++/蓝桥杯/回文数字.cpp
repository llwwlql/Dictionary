#include <stdio.h>
#include <string.h>

int main()
{
	int i,j,len,sum,n,peace;
	char str[10];
	scanf("%d",&n);

	for(i=10000;i<=100000;i++)
	{
		sprintf(str,"%d",i);
		len=strlen(str);
		peace=1;
		sum=0;
		for(j=0;j<=len && peace;j++)
		{
			if(str[j]!=str[len-j])
				peace=0;
			if(peace)
				sum+=str[j]-'0';
		}
		if(peace && n==sum)
			printf("%d\n",i);
	}
	
	return 0;
}
