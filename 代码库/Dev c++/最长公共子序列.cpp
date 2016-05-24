//最长公共子序列
#include <stdio.h>
#include <string.h>
int a[1005][1005];
void LCSLength(char *str1,char *str2,int len1,int len2)
{
	int i,j;
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(str1[i-1]==str2[j-1])
				a[i][j]=a[i-1][j-1]+1;
			else if(a[i-1][j]>=a[i][j-1])
				a[i][j]=a[i-1][j];
			else
				a[i][j]=a[i][j-1];
		}
	}
	printf("%d\n",a[len1][len2]);
}

int main()
{
	char str1[1005],str2[1005];
	while(~scanf("%s %s",str1,str2))
		LCSLength(str1,str2,strlen(str1),strlen(str2));
	return 0;
}
