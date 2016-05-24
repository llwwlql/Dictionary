#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int a[1005];
int temp[1005];
int peace,sum,n;

int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}

void dfs(int num,int t,int m)
{
	int i;
	if(num>sum)
		return ;
	if(num==sum)
	{
		peace=0;
		printf("%d",temp[0]);
		for(i=1;i<t;i++)
			printf("+%d",temp[i]);
		putchar('\n');
		return ;
	}
	
	for(i=m;i<=n;i++)
	{
		temp[t]=a[i];
		dfs(num+a[i],t+1,i+1);
		while(i+1<=n && a[i]==a[i+1])	//重复数据处理 
			i++;
	}
}

int main()
{
	int num;
	int i,j;
	while(scanf("%d %d",&sum,&n),sum||n)
	{
		num=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		printf("Sums of %d:\n",sum);
		qsort(&a[1],n,sizeof(a[1]),cmp);
		peace=1;
		dfs(0,0,1);
		if(peace)
			printf("NONE\n");
	}
	return 0;
}
