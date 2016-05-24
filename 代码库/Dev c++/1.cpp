#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}

typedef struct note{
	int x,y;
}Note;

typedef struct t{
	int x1,x2,y1,y2;
	int data;
}T;
T a[105];

Note b[20005];

int c[20005];

int main()
{
	int n,m,i,j;
	scanf("%d %d",&m,&n);
	memset(c,0,sizeof(c));
	for(i=0;i<m;i++)
		scanf("%d %d",&b[i].x,&b[i].y);
	for(j=0;j<n;j++)
	{
		scanf("%d %d %d %d",&a[j].x1,&a[j].y1,&a[j].x2,&a[j].y2);
		a[j].data=2*(a[j].x2-a[j].x1+a[j].y2-a[j].y1);
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i].x>=a[j].x1 && b[i].x<=a[j].x2 && b[i].y>=a[j].y1 && b[i].y<=a[j].y2)
			{
				c[i]=a[j].data;
				break;
			}
		}
	}
	
	qsort(c,m,sizeof(c[0]),cmp);
	
	for(i=0;i<m;i++)
		printf("%d\n",c[i]);
	
	return 0;
}
