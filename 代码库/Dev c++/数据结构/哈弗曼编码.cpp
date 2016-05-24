//    ��1���������������Ĵ洢�ṹ��
//    ��2����ƹ��������룬�������
//    ��3�����ݸ����ĵ��ģ�����õ��ĵı��롣 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree{
	int parent,lchild,rchild;
	int weight;
	char Node;
}HNode,*HTree;
char Node[105];
void Selete(HTree HT,int n,int &s1,int &s2)
{
	int i;
	int min1=1000000,min2=1000000;
	for(i=1;i<=n;i++)
	{
		if(HT[i].parent==0)
		{
			if(min1>HT[i].weight)
			{
				min2=min1;s2=s1;
				min1=HT[i].weight;
				s1=i;
			}
			else if(min2>HT[i].weight)
			{
				s2=i;
				min2=HT[i].weight;
			}

		}
	}
}

void InitHuffmanTree(HTree &bt,int *w,int n)
{//������������
	int i,m;
	int s1,s2;
	m=2*n-1;
	if(n<=1)
		return ;
	bt=(HTree)malloc((m)*sizeof(HNode));
	for(i=0;i<=n;i++)
	{
		bt[i].weight=w[i];
		bt[i].Node=Node[i];
		bt[i].parent=bt[i].rchild=bt[i].lchild=0;
	}

	for(;i<=m;i++)
		bt[i].weight=bt[i].lchild=bt[i].rchild=bt[i].parent=0;
	for(i=n+1;i<=m;i++)
	{
		s1=s2=0;
		Selete(bt,i-1,s1,s2);
		bt[i].lchild=s1;
		bt[i].rchild=s2;
		bt[i].weight=bt[s1].weight+bt[s2].weight;
		bt[s1].parent=i;
		bt[s2].parent=i;
	}
}

void HuffmanCoding(HTree bt,char HC[][100],int n)
{//���й���������
	char *cd;
	int start;
	int c,f,i;
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;
		for(c=i,f=bt[i].parent;f!=0;c=f,f=bt[f].parent)
			if(bt[f].lchild==c)
				cd[--start]='0';
			else
				cd[--start]='1';
		strcpy(HC[i],&cd[start]);
	}
	for(i=1;i<=n;i++)
		printf("%c %s\n",Node[i],HC[i]);
	free(cd);
}
void Decode(HTree bt,int n)
{//���� 
	char code[1005];
	int i,j,len,p;
	printf("������һ�����룺"); 
	scanf("%s",code);
	len=strlen(code);
	p=2*n-1;
	printf("������Ϊ��");
	for(i=0;i<=len;i++)
	{
		if(bt[p].lchild==0 && bt[p].rchild==0)
		{
			printf("%c",bt[p].Node);
			p=2*n-1;
		}
		if(code[i]=='0')
			p=bt[p].lchild;
		else if(code[i]=='1')
			p=bt[p].rchild;
	}
	putchar('\n');
}
int main()
{
	HTree bt;
	char HC[100][100];
	int n,i;
	int weight[105];
	char yn;
	printf("���������ݵĸ���:");
		scanf("%d",&n);
	printf("������ÿ�����ݵ����ƺ�Ȩ��:\n");
	weight[0]=0;
	for(i=1;i<=n;i++)
	{
		getchar();
		scanf("%c %d",Node+i,weight+i);
	} 

	InitHuffmanTree(bt,weight,n);
	printf("������Ϊ��\n");
	HuffmanCoding(bt,HC,n);

	while(1)
	{
		getchar();
		printf("�Ƿ�������룿��Y/N����");
		scanf("%c",&yn);
		if(yn=='y' || yn=='Y')
			Decode(bt,n);
		else
			break;
	}
	return 0;
}
