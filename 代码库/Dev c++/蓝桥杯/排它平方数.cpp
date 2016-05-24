#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	long long sum;
	char str1[20];
	int a[10],len,j,i,peace;
	for(i=100000;i<1000000;i++)
	{
		memset(a,0,sizeof(a));
		sprintf(str1,"%d",i);
		
		for(i=0;i<6;i++)
			a[str1[i]-'0']=1;
		sum=i*i;
		sprintf(str1,"%d",sum);
		len=strlen(str1);
		for(j=0;j<len;j++)
			if(a[str1[j]-'0']==1)
			{
				peace=1;
				break;
			}
		if(!peace)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
