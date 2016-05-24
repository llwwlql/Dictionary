#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	  int weight;
	  int parent,lchild,rchild;
	  char node;
}HTNode,*HuffmanTree;
char node[10];
typedef char **HuffmanCode;
void Select(HuffmanTree HT,int n,int &s1,int &s2)
{//在HT[1]到HT[t-1]中找出权值最小的两个S1和S2
	int i=1;
	int min1=10000,min2=10000;
	s1=s2=0;
	while(i<=n)
	{
        if(HT[i].parent==0)
        {
			if(min1>HT[i].weight)
			{
				min2=min1;
				s2=s1;
				min1=HT[i].weight;
				s1=i;
			}
			else if(min2>HT[i].weight)
			{
				s2=i;
				min2=HT[i].weight;
			}
        }
        i++;
	}
}

void CreateHuffman(HuffmanTree &HT,int *w,int n)
{//w存放n个字符的权值，构造哈夫曼树HT
	int i,s1,s2;
	int m=2*n-1;
	if(n<=1)
        return ;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(i=0;i<=n;i++,++w)
	{
		HT[i].weight=*w;
		HT[i].node=node[i];
		HT[i].lchild=0;
		HT[i].parent=0;
		HT[i].rchild=0;
	}
	for(;i<=m;++i)
	{
		HT[i].weight=0;
		HT[i].lchild=0;
		HT[i].parent=0;
		HT[i].rchild=0;
	}
	for(i=n+1;i<=m;i++)
    {//建立哈夫曼树
        s1=s2=0;
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;HT[s2].parent=i;
        HT[i].lchild=s1;HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
}

void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n)
{//求出n个字符的哈夫曼编码HC
    int i;
    HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	char *cd=(char*)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;++i)
	{
		int start=n-1;
	    for(int c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
            if(HT[f].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],cd+start);
	}
	for(i=1;i<=n;i++)
	{
	   printf("%c %d的编码为: %s\n",node[i],HT[i].weight,HC[i]);
	}
	free(cd);
}

void HuffmanDecode(HuffmanTree HT,int n)
{//对编码进行译码
	char decode[100];
	int i,len,p;
	printf("请输入需要译码的编码:\n");
	scanf("%s",decode);
	len=strlen(decode);
	p=2*n-1;
	printf("该编码的译码结果为:\n");
	for(i=0;i<=len;i++)
	{
		if(HT[p].lchild==0 && HT[p].rchild==0)
		{
			printf("%c",HT[p].node);
			p=2*n-1;
		}
		if(decode[i]=='0')
			p=HT[p].lchild;
		else if(decode[i]=='1')
			p=HT[p].rchild;
	}
	putchar('\n');
}

int main ()
{
	HuffmanTree HT;
    HuffmanCode HC;
    int i,n;
    int w[100];
    printf("请输入字符的个数:\n");
    scanf("%d",&n);
    printf("请输入%d个字符所对应的名称和权值:\n",n);
    w[0]=0;
    for(i=1;i<=n;i++)
	{
	    getchar();
	    scanf("%c%d",&node[i],&w[i]);
	}
	CreateHuffman(HT,w,n);
	HuffmanCoding(HT,HC,n);
	HuffmanDecode(HT,n);
	return 0;
}
