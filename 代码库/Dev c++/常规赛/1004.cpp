#include <stdio.h>
int main()
{
	int n;
	int i,j;
	int a[1005][2];
	int Num=0;
	while(scanf("%d",&n),n)
	{
		Num++;
		for(i=0;i<n;i++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		if(Num!=1)
			putchar('\n');
		printf("Case %d:\n",Num);
		for(i=0;i<n;i++)
		{
			int r=a[i][0],c=a[i][1];
			int index1=1000000,index2=1000000;
			for(j=0;j<n;j++)
			{
				if(a[j][0]>r && a[j][1]>c)
				{
					if(a[j][0]<index1)
					{
						index1=a[j][0];
						index2=a[j][1];
					}
					else if(a[j][0]==index1 && a[j][1]<index2)
					{
						index1=a[j][0];
						index2=a[j][1];
					}
				}
			}
			if(index1==1000000 && index2==1000000)
				printf("-1 -1\n");
			else
				printf("%d %d\n",index1,index2);
		}
	}
	
	return 0;
}
