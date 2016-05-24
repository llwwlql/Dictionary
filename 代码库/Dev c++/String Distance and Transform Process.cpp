#include <stdio.h>
#include <string.h>
int m[100][100];
int s[100][100];
char index[85];
int peace;
void LCSLength(char *str1,char *str2,int len1,int len2)
{
	int i,j;
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				m[i][j]=m[i-1][j-1]+1;
				s[i][j]=1;
			}
			else if(m[i-1][j]>m[i][j-1])
			{
				m[i][j]=m[i-1][j];
				s[i][j]=2;
			}
			else
			{
				m[i][j]=m[i][j-1];
				s[i][j]=3;
			}
		}
	}
}

void LCS(char *str1,int i,int j)
{
	if(i==0 || j==0)
		return ;
	if(s[i][j]==1)
	{
		LCS(str1,i-1,j-1);
		index[peace++]=str1[i-1];
	}
	else if(s[i][j]==2)
		LCS(str1,i-1,j);
	else
		LCS(str1,i,j-1);
	
}

int fun(char *str,char ch,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(str[i]==ch)
			return i;
	}
}

int main()
{
	char str1[85],str2[85];
	int i,j;
	int temp1,temp2,MAX_SUM;
	int len1,len2;
	int key1,key2;
	while(~scanf("%s%*c%s%*c",str1,str2))
	{
		peace=0;
		key1=0;key2=0;
		memset(m,0,sizeof(m));
		LCSLength(str1,str2,strlen(str1),strlen(str2));
		LCS(str1,strlen(str1),strlen(str2));
		len1=strlen(str1);
		len2=strlen(str2);
		
		MAX_SUM=len1>len2? len1-m[len1][len2]:len2-m[len1][len2];
		
		printf("%d\n",MAX_SUM);
		
		temp1=fun(str1,index[0],len1);
		temp2=fun(str2,index[0],len2);
		i=0
		while(i<MAX_SUM)
		{
			if(temp2==0 && temp1!=temp2)
			{
				printf("%d Delete 1",i);
				key1++;
				i++;
			}
			else if()
			
		}		
	}
	return 0;
}
