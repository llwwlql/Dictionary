#include <stdio.h>
typedef struct{
	int l,r;
	long long sum;
}Tree;
Tree T[140000];
int a[50005];
void build(int x,int y,int i)
{
	T[i].l=x;
	T[i].r=y;
	if(x==y)
	{
		T[i].sum=a[y];
		return ;
	}
	int mid=(x+y)/2;
	build(x,mid,2*i);
	build(mid+1,y,2*i+1);
	T[i].sum=T[2*i].sum+T[2*i+1].sum;
}

long long find_sum(int x,int y,int i)		//x是左边界，y是右边界，i是当前树的节点 
{
	if(T[i].l==x && T[i].r==y)
		return T[i].sum;
	int mid=(T[i].l+T[i].r)/2;
	if(y<=mid)
		return find_sum(x,y,2*i);
	else if(x>mid)
		return find_sum(x,y,2*i+1);
	else
		return find_sum(x,mid,2*i)+find_sum(mid+1,y,2*i+1);
}

void updata(int x,int y,int i)
{
	T[i].sum+=y;
	if(T[i].l==x && T[i].r==x)
		return ;
	int mid=(T[i].l+T[i].r)/2;
	if(x<=mid)
		updata(x,y,2*i);
	else
		updata(x,y,2*i+1);
}

int main()
{
	int t,n;
	int i,peace,x,y,j;
	char str[10];
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		printf("Case %d:\n",j);
		peace=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		build(1,n,1);
		while(peace)
		{
			scanf("%s",str);
			switch(str[0])
			{
				case 'Q':
					scanf("%d %d",&x,&y);
					printf("%I64d\n",find_sum(x,y,1));
					break;
				case 'A':
					scanf("%d %d",&x,&y);
					updata(x,y,1);
					break;
				case 'S':
					scanf("%d %d",&x,&y);
					updata(x,-y,1);
					break;
				case 'E':
					peace=0;
					break;
			}
			
		}
	}
	
	return 0;
}
