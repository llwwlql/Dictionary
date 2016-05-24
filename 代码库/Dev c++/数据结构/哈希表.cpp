#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int n;
typedef struct{
	int *elem;
	int count;
	int length;
}HushTable;

typedef struct node{
	int data;
	struct node *next;
}*List,Node;

typedef struct {
	List elem;
	int count;
	int length;
}ChainHush;

void InputNumber(int *a)
{
	int i,j;
	srand(time(0));
	printf("Please input number count:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		a[i]=rand()%89+10;
		printf("%d ",a[i]);
	}
	putchar('\n');
}

int Hush(int m,int t)
{//��ϣ���� 
	return m%(t*n);
}

void Init_HushTable(HushTable &H,int *a)
{
	int i,j,k;
	int d[205];
	H.length=2*n;
	H.count=0;
	H.elem=(int *)malloc(sizeof(int)*H.length);
	for(i=0;i<H.length;i++)
		H.elem[i]=0;	//����ֵ
	d[0]=0;
	for(i=1;i<=H.length;i++)
		d[i]=d[i-1]+1;
	//��ͻ���� 
	for(i=0;i<n;i++)
	{
		k=Hush(a[i],2);
		j=1;
		while(H.elem[k]!=0)
			k=Hush(a[i]+d[j++],2);
		H.elem[k]=a[i];
		H.count++;
	}
	printf("�����ɹ���\n");
}

void Init_ChainHush(ChainHush &CH,int *a)
{
	int i,j,k;
	List p,s;
	CH.length=n;
	CH.count=0;
	CH.elem=(List)malloc(sizeof(Node)*CH.length);
	for(i=0;i<CH.length;i++)
		CH.elem[i].next=NULL;
	
	for(i=0;i<n;i++)
	{
		k=Hush(a[i],1);
		p=&CH.elem[k];
		while(p->next)
			p=p->next;
		s=(List)malloc(sizeof(Node));
		s->data=a[i];
		s->next=NULL;
		p->next=s;
		CH.count++;
	}
	printf("�����ɹ���\n");
}

void Search_HushTable(HushTable H,int num)
{
	int i,j,k;
	char yn;
	int d[205];
	for(i=1;i<=H.length;i++)
		d[i]=d[i-1]+1;
	//��ͻ����
	k=Hush(num,2);
	j=1;
	while(H.elem[k])
	{
		if(H.elem[k]==num)
		{
			printf("���ҳɹ���\n");
			return ;
		}
		k=Hush(num+d[j++],2);
	}
	printf("����ʧ�ܣ�%d�����ڣ��Ƿ���Ӹ����ݣ�(Y/N):",num);
	getchar();
	scanf("%c",&yn);
	if(yn=='Y' || yn=='y')
	{
		if(H.count+1<H.length)
		{
			H.elem[k]=num;
			H.count++;
			printf("��ӳɹ�.\n");
		}
		else
			printf("���ʧ��.(ԭ�򣺹�ϣ��ռ�����)\n");
	}
}

void Search_ChainHush(ChainHush CH,int num)
{
	int i,j,k;
	char yn;
	List p,s;
	k=Hush(num,1);
	p=&CH.elem[k];
	while(p->next)
	{
		if(p->next->data==num)
		{
			printf("���ҳɹ���\n");
			return ;
		}
		p=p->next;
	}
	printf("����ʧ�ܣ�%d�����ڣ��Ƿ���Ӹ����ݣ�(Y/N):",num);
	getchar();
	scanf("%c",&yn);
	if(yn=='Y' || yn=='y')
	{
		s=(List)malloc(sizeof(Node));
		s->data=num;
		s->next=NULL;
		p->next=s;
		CH.count++;
		printf("��ӳɹ�.\n");
	}	
}

int main()
{
	int key,num;
	int a[105],i;
	int peace1;
	List p;
	HushTable H;
	ChainHush CH;
	while(1)
	{
		printf("	--------------------------------\n");
		printf("	1���������ݡ�\n");
		printf("	2��������̽����ɢ�з�������ϣ��\n");
		printf("	3������ַ��������ϣ��\n");
		printf("	4�����ҡ�\n");
		printf("	5���˳���\n");
		printf("	--------------------------------\n");
		
		scanf("%d",&key);
		
		switch(key)
		{
			case 1:
				InputNumber(a);
				break;
			case 2:
				Init_HushTable(H,a);
				peace1=1;
				break;
			case 3:
				Init_ChainHush(CH,a);
				peace1=0;
				break;
			case 4:
				printf("Please input search number:");
				scanf("%d",&num);
				if(peace1)
					Search_HushTable(H,num);
				else
					Search_ChainHush(CH,num);
				break;
			default:
				return 0;
		}
	}
}
