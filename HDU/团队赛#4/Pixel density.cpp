#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
char str[1005];
char str2[105],str3[105],str4[105],str5[105],str6[105];
void init()
{
	memset(str,0,sizeof(str));
	memset(str2,0,sizeof(str2));
	memset(str3,0,sizeof(str3));
	memset(str4,0,sizeof(str4));
	memset(str5,0,sizeof(str5));
	memset(str6,0,sizeof(str6));
}

int main()
{
	int i,j;
	int T,n=0;
	scanf("%d",&T);
	while(T--)
	{
		double a,sum;
		init();
		int wi,hi;
		scanf("%d%*c",&n);
		gets(str);
		int len=strlen(str),temp,index=1;
		
		for(i=0;i<len;i++)
		{
			if(str[i]>='0' && str[i]<='9' && (isdigit(str[i+1]) || str[i+1]=='.' || str[i+1]==' '))
			{
				while(str[i-index]==' ')
					index++;
				break;
			}
			str2[i]=str[i];
		}
		str2[i-index+1]='\0';	//电子产品名字
		temp=i;
		
		//printf("%s",str2);
		
		for(i=temp;i<len;i++)
		{
			if(str[i]>='0' && str[i]<='9' || str[i]=='.')
				str3[i-temp]=str[i];
			else
				break;
		}
		int zhengshu=0,xiaoshu=0,weishu=0;
		str3[i-temp]='\0';
		weishu=i-temp;
		a=atof(str3);		//转成double
		
		while(!(str[i]>='0' && str[i]<='9'))
			i++;
		temp=i;
		for(i=temp;i<len;i++)
		{
			if(str[i]>='0' && str[i]<='9')
				str4[i-temp]=str[i];
			else
				break;
		}
		hi=atoi(str4);		//转成int 
		
		while(!(str[i]>='0' && str[i]<='9'))
			i++;
		temp=i;
		
		for(i=temp;i<len;i++)
		{
			if(str[i]>='0' && str[i]<='9')
				str6[i-temp]=str[i];
			else
				break;
		}
		wi=atoi(str6);	//转成int 
		temp=i;
		
		
		for(i=temp;i<len;i++)
			str5[i-temp]=str[i];
		str5[len-temp]='\0';
		for(i=0;i<strlen(str5);i++)
			str5[i]=tolower(str5[i]);
		if(sqrt(a-0.0)<0.000001)
			sum=0;
		else
			sum=sqrt(wi*wi+hi*hi)/a;
		n++;
		printf("Case %d: The%s of %s's PPI is %.2lf.\n",n,str5,str2,sum);
	}
	return 0;
}
