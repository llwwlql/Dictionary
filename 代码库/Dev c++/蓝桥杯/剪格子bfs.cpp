#include <stdio.h>
#include <queue>
using namespace std;
typedef struct{
	int x,y,val;
}V;

V a[105];

int sum=0,min=105;

void bfs(int x,int y,int val)
{
	queue <int> q_x,q_y,q_val;
	q_x.push(x);
	q_x.push(y);
	q_x.push(val);
	
}

int main()
{
	int n,m;
	int i,j,k;
	scanf("%d %d",&m,&n);
	k=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",a[k]);
			sum+=a[i]+j;
		}
		
	bfs(1,1,a[1][1]);
	if(min!=105)
		printf("%d\n",min);
	else
		printf("0\n");
	
	return 0;
}
