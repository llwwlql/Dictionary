#include <stdio.h>
int n;
void sort(int *s,int *f)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(f[i]>f[j])
			{
				temp=f[i];
				f[i]=f[j];
				f[j]=temp;
				
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
}

int main()
{
	int s[105],f[105];
	int index,i,j;
	while(~scanf("%d",&n),n)
	{
		index=1;
		for(i=1;i<=n;i++)
			scanf("%d %d",s+i,f+i);
		sort(s,f);
		j=1;
		for(i=2;i<=n;i++)
		{
			if(s[i]>=f[j])
			{
				index++;
				j=i;
			}
		}
		printf("%d\n",index);
	}
	
	return 0;
}
