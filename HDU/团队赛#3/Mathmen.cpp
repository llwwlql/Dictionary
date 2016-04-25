#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct node{
	int dis,IQ;
}Node;

Node b[100005];
int c[100005];

int cmp(Node a,Node b)
{
	return a.dis<b.dis;
}

int main()
{
	int T;
	int n,m;
	int a[10005];
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		int sum=0;
		memset(c,0,sizeof(c));
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&b[i].dis,&b[i].IQ);
			sum+=b[i].dis;
		}
		if(sum<n)
			printf("Impossible\n");
		else
		{
			long long ans=0;
			int peace=1;
			sort(b,b+m,cmp);
			
			for(i=0;i<n-1;i++)
			{
				int dist=a[i+1]-a[i];
				for(j=0;j<m;j++)
				{
					if(dist<=b[j].dis && !c[j])
					{
						ans+=b[j].IQ;
						c[j]=1;
						break;
					}
				}
				if(j==m)
				{
					printf("Impossible\n");
					peace=0;
					break;
				}
			}
			if(peace)
				printf("%I64d\n",ans);
		}
	}
	return 0;
}
