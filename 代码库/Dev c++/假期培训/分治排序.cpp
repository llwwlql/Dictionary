#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NUM 100000
void Merge(int *a,int p,int q,int r)			//�ϲ� 
{
	int n1,n2,i,j,k;
	n1=q-p+1;									//������鳤�� 
	n2=r-q;										//�ұ����鳤��
	
	int *L,*R;
	L=(int *)malloc((n1+2)*sizeof(int));		//������������ 
	R=(int *)malloc((n2+2)*sizeof(int));
	for(i=1;i<=n1;i++)
		L[i]=a[p+i-1];
	for(j=1;j<=n2;j++)
		R[j]=a[q+j];
	
	L[n1+1]=NUM;								//��һ�����ֵ�ŵ�����ĩβ��Ϊ�ڱ���¶���ڱ�˵������Ϊ�� 
	R[n2+1]=NUM;
	
	i=j=1;
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
	}
	free(L);
	free(R);
	
}

void Merge_sort(int *a,int l,int r)				//���� 
{
	if(l<r)
	{
		int mid=floor((l+r)/2);
		Merge_sort(a,l,mid);
		Merge_sort(a,mid+1,r);
		Merge(a,l,mid,r);
	}
}

int main()
{
	int n,i,j;
	int a[100];
	scanf("%d",&n);
	srand(time(0));
	for(i=1;i<=n;i++)
		a[i]=rand()%101;
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	putchar('\n');
	
	Merge_sort(a,1,n);
	
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	putchar('\n');
	
	return 0;
}
