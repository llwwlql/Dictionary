#include <stdio.h>
#include <string.h>
int pre[100005];
int ans[100005];
int temp[100005];

int find(int x)
{
	int r=x;
	while(pre[r]!=r)
		r=pre[r];
	int i=x,j;
	while(i!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;		
	}
	return r;
}

void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
		pre[fx]=fy;
}

int main()
{
	int i,j;
	int a,b,index,count,number;
	while(scanf("%d %d",&a,&b),a!=-1 && b!=-1)
	{
		memset(ans,0,sizeof(ans));
		index=0;
		number=1;
		ans[a]=1;
		ans[b]=1;
		for(i=1;i<=100000;i++)
			pre[i]=i;
		merge(a,b);
		while(a!=0 && b!=0)
		{
			scanf("%d %d",&a,&b);
			ans[a]=1;
			ans[b]=1;
			merge(a,b);
			number++;
		}
		count=0;
		
		for(i=1;i<=100000;i++)
			if(ans[i])
				temp[count++]=i;
		
		
		for(i=0;i<count;i++)
		{
			if(pre[temp[i]]==temp[i])
				index++;
		}
		if(index==1 && number+1==count || number==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	
	return 0;
}
