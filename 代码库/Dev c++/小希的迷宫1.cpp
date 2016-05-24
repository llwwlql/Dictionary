#include <stdio.h>
#include <string.h>
#define MAX 100005
int pre[MAX];
int a[MAX];
int flag;
int find(int x)
{//并查集找根节点 
	int r=x;
	while(r!=pre[r])
		r=pre[r];
	return r;
}

void Merge(int x,int y)
{//将两个点连同 
	int fx=find(x),fy=find(y);
	if(fx!=fy)
		pre[fx]=fy;
	else
		flag=0;		//之前已经连通，此时形成了环 
}

int main()
{
	int x,y;
	int i,j;
	int count,index;
	while(scanf("%d %d",&x,&y),x!=-1 && y!=-1)
	{
		flag=1;
		memset(a,0,sizeof(a));
		a[x]=a[y]=1;
		
		if(x==0 && y==0)	//0 0时也是符合的 
			flag=1;		
		else
		{	
			count=1;
			for(i=1;i<MAX;i++)
				pre[i]=i;
			Merge(x,y);
			while(scanf("%d %d",&x,&y),x!=0 && y!=0)
			{
				
				Merge(x,y);
				a[x]=a[y]=1;
			}
			index=0;
			
			for(i=1;i<MAX;i++)
				if(a[i])
					if(pre[i]==i)	//index==1时即连通 
						index++;
			if(index!=1)
				flag=0;	
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
