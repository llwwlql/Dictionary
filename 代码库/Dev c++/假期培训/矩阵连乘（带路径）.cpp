#include <stdio.h>
int main()
{
	int p[100];
	int m[100][100];
	int s[100][100];
	int i,j,k,r,n;
	printf("Ҫ����ľ��������");
	scanf("%d",&n);
	printf("����ÿ��������к��У�p0,p1,p2...����");	//��������һά����洢�к��� 
	for(i=0;i<=n;i++)
		scanf("%d",p+i);
	for(i=1;i<=n;i++)		//һ��Ҫ��ס��m[i][i]Ҫ����ֵ 
		m[i][i]=0;
	for(r=2;r<=n;r++)
	{
		for(i=1;i<=n-r+1;i++)
		{
			j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; 
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(k=1;k<i;k++)
			printf("     ");
		for(j=i+1;j<=n;j++)
		{
			
			printf("%5d",m[i][j]);
		}
		putchar('\n');
	}
	printf("���Ͻ�Ϊ���Ž�.\n");
	for(i=1;i<=n;i++)
	{
		for(k=1;k<i;k++)
			printf("     ");
		for(j=i+1;j<=n;j++)
		{
		
			printf("%5d",s[i][j]);
		}
		putchar('\n');
	}
	
	return 0;
}
