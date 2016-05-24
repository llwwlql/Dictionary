#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,len1,len2;
	char str[1005],a[1005];
	while(scanf("%s",str),str[0]!='#')
	{
		int index=0;
		scanf("%s",a);
		len1=strlen(str);
		len2=strlen(a);
		for(i=0;i<len1;i++)
		{
			for(j=0;j<len2;j++)
				if(str[i+j]!=a[j])
					break;
			if(j==len2)
			{
				index++;
				i=i+j-1;
			}
			
		}
		printf("%d\n",index);
	}
	
	return 0;
}
