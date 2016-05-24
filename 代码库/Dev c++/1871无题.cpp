#include <stdio.h>
typedef struct hotel{
	int num;
	int sum;
	int money;
}hotle;
hotle a[105];
int c;
void swap(hotle &a,hotle &b)
{
	hotle temp;
	temp=a;
	a=b;
	b=temp;
}

void sort()
{
	int i,j;
	for(i=0;i<c-1;i++)
	{
		for(j=i+1;j<c;j++)
		{
			if(a[i].sum>a[j].sum)
				swap(a[i],a[j]);
			else if(a[i].sum==a[j].sum)
			{
				if(a[i].money>a[j].money)
					swap(a[i],a[j]);
			}
		}
	}
}

int main()
{
	int T,n,i,j;
	int stu;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&c);
		int max=0;
		for(i=0;i<c;i++)
		{
			scanf("%d %d %d",&a[i].num,&a[i].sum,&a[i].money);
			if(a[i].sum>max)
				max=a[i].sum;
		}
		sort();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&stu);
			if(stu>max)
				printf("sorry\n");
			else
			{
				for(j=0;j<c;j++)
				{
					if(stu==a[j].sum)
					{
						printf("%d\n",a[j].num);
						break;
					}
				}
			}
		}
	}
	
	return 0;
}
