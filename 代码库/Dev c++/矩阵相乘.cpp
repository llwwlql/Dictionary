#include <stdio.h>
int a[1005][1005];			//��¼������� 
int s[1005][1005];			//��¼����λ�� 
int main()
{
	int p[1005];
	int n,i,j,k,r;
	scanf("%d",&n);
	for(i=0;i<=n;i++)		//p�����Ǽ�¼�����к��� 
		scanf("%d",p+i);
	for(i=0;i<=n;i++)
		a[i][i]=0;
	for(r=2;r<=n;r++)		//r�Ǵ�������һ�𻮷� 
	{
		for(i=1;i<=n-r+1;i++)
		{
			j=r+i-1;
			a[i][j]=a[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(k=i+1;k<j;k++)
			{
				int t=a[i][k]+a[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<a[i][j])
				{
					a[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
	printf("���ٳ˴���Ϊ:%d\n",a[1][n]);
	for(i=1;i<=n;i++)			//��ӡ������� 
	{
		for(j=1;j<i;j++)
			printf("      ");
		for(j=i+1;j<=n;j++)
			printf("%6d",a[i][j]);
		putchar('\n');
	}
	putchar('\n');
	for(i=1;i<=n;i++)			//��ӡ�ָ�λ�þ��� 
	{
		for(j=1;j<i;j++)
			printf("     ");
		for(j=i+1;j<=n;j++)
			printf("%5d",s[i][j]);
		putchar('\n');
	}
	
	return 0;
}
