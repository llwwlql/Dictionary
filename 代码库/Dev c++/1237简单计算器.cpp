#include <stdio.h>
#include <string.h>
int main()
{
	char ch1,ch2,str[205],strn[205];
	double a[205];
	int i,j,len,index,k;
	while(scanf("%s",strn),!(strn[0]=='0' && strn[1]=='\0'))
	{
		len=strlen(strn);
		j=0;k=1;
		str[0]=' ';
		for(i=0;i<len;i+=4)
		{

			a[j++]=strn[i]-'0';
			if(str[k-1]=='*')
			{
				a[j-2]=a[j-1]*a[j-2];
				j--;
				k--;
			}
			else if(str[k-1]=='/')
			{
				a[j-2]=a[j-1]*1.0/a[j-2];
				j--;
				k--;
			}
			
			str[k++]=strn[i+2];
		}
		
		double sum=a[0];
		for(i=0;i<=j;i++)
		{
			if(str[i]=='+')
				sum+=a[i+1];
			else
				sum-=a[i+1];
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
