#include <stdio.h>
int main()
{
	int n,m;
	int i,j,k,l;
	int s,t;
	int sum,index;
	int a[100002];
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	while(m--)
	{
		sum=0;
		scanf("%d %d",&s,&t);
		for(i=0;i<=t-s;i++)		//�����м���Ԫ�� 
		{
			for(j=s;j<=t;j++)	//���䷶Χ 
			{
				if(j+i<=t)
				{
					if(i%2)
						index=0;
					else if(i%2==0)
						index=a[(j+j+i)/2];
					for(k=j,l=j+i;k<l;k++,l--)		//�ж� 
					{
						index=index+a[k]+a[l];
						if(a[k]!=a[l])
						{
							index=0;
							break;
						}
					}
					sum+=index;
				}
			}
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
