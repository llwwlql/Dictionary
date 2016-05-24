#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	int i,j,temp,index;
	int a[1005],b[1005];		//a数组存数，b数组判断是否被拦截，拦截了记录1，未拦截记录0 
	while(~scanf("%d",&n))
	{
		temp=1;
		index=0;
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		while(temp)
		{
			temp=0;
			int max=30005;
			for(i=1;i<=n;i++)
			{
				if(b[i]==0)
				{
					if(max>a[i])
					{
						max=a[i];
						b[i]=1;
					}
					temp=1;			//未全部拦截完的标志 
				}
			}
			index++;
		}
		printf("%d\n",index-1);
	}
	
	return 0;
}
