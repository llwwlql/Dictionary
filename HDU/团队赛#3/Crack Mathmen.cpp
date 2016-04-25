	#include <stdio.h>
	#include <string.h>
	long long powerMod(long long a,long long b,long long c)
	{
		long long ans=1;
		a=a%c;
		while(b>0)
		{
			if(b%2==1)
				ans=(ans*a)%c;
			b=b/2;
			a=(a*a)%c;
		}
		return ans;
	}
	
	int main()
	{
		int i,j;
		int T;
		int b,c;
		long long n;
		char a[1005],str[1000005];
		scanf("%d",&T);
		while(T--)
		{
			int peace=0;
			scanf("%I64d%*c",&n);
			memset(a,' ',sizeof(a));
			for(i=0;i<26;i++)
			{
				long long ans=powerMod('a'+i,n,997);
				if(a[ans]==' ')
					a[ans]='a'+i;
				else
				{
					peace=1;
					break;
				}
			}
			
			for(i=0;i<26 && !peace;i++)
			{
				long long ans=powerMod('A'+i,n,997);
				if(a[ans]==' ')
					a[ans]='A'+i;
				else
				{
					peace=1;
					break;
				}
			}
			
			for(i=0;i<10 && !peace;i++)
			{
				long long ans=powerMod('0'+i,n,997);
				if(a[ans]==' ')
					a[ans]='0'+i;
				else
				{
					peace=1;
					break;
				}
			}
			scanf("%s",str);
			if(!peace)
			{
					int len=strlen(str);
					for(i=0;i<len;i+=3)
					{
						int ans;
						ans=(str[i]-'0')*100+(str[i+1]-'0')*10+(str[i+2]-'0');
						if(a[ans]!=' ')
							printf("%c",a[ans]);
						else
						{
							printf("No Solution");
							break;
						}
					}
					putchar('\n');
			}
			else
			{
				printf("No Solution\n");
			}
		}	
		return 0;
	}
