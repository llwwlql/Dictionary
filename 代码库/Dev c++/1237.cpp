#include <stdio.h>
#include <string.h>
int main()
{
	char ch1,ch2,str[205],strn[205];
	double a[205];
	int i,j,len,index,k;
	while(gets(strn),!(strn[0]=='0' && strn[1]=='\0'))
	{
		len=strlen(strn);
		j=0;
		k=1;
		str[0]=' ';
		
		for(i=0;i<len;i+=4)		//每4个字符看成一组数据 
		{
			
			a[j]=strn[i]-'0';		//将字符改成数字 
			while(strn[i+1]<='9' && strn[i+1]>='0')
				a[j]=a[j]*10+strn[++i]-'0';
			j++;
			
			if(str[k-1]=='*')		//把乘法和除法先算出结果 
			{
				a[j-2]=a[j-1]*a[j-2];
				j--;
				k--;
			}
			else if(str[k-1]=='/')
			{
				a[j-2]=a[j-2]*1.0/a[j-1];
				j--;
				k--;
			}
			str[k++]=strn[i+2];
		}	
		double sum=a[0];
		for(i=1;i<j;i++)		//最后求加减 
		{
			if(str[i]=='+')
				sum+=a[i];
			else if(str[i]=='-')
				sum-=a[i];
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
