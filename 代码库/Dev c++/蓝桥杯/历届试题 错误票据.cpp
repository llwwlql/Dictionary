#include <stdio.h>
#include <string.h>
int main()
{
	char str[100005];
	int n,i,j,len,peace,index1,index2;
	int a[100005],max;
	scanf("%d%*c",&n);
	for(i=0;i<100005;i++)
		a[i]=0;
	max=-1;
	while(n--)
	{
		gets(str);
		len=strlen(str);
		j=0;
		for(i=0;i<len;i++)
		{
			peace=0;
			while(str[i]>='0' && str[i]<='9')
				peace=peace*10+str[i++]-'0';
			
			if(peace>max)
				max=peace;
			a[peace]++;
		}
	}
	for(i=1;i<=max;i++)
		if(a[i])
			break;
	for(j=i;j<=max;j++)
	{
		if(a[j]==0)
			index1=j;
		else if(a[j]>1)
			index2=j;
	}
	printf("%d %d\n",index1,index2);
	putchar('\n');
	
	return 0;
}
