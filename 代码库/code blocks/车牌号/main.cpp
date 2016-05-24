#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct{
    char name[20];
}CarName;

typedef struct
{
    CarName *elem;
    int length;
}LinkList;
void Iuput(LinkList &L)
{
    printf("���복����Ϣ:\n");
    printf("���복����Ŀ:");
    scanf("%d",&L.length);
	L.elem=(CarName*)malloc(L.length*sizeof(CarName));
    printf("���복�ƺ�(��ĸ������):\n");
    for(int i=1;i<=L.length;i++)
        scanf("%s",&L.elem[i]);
}

void BubbleSort(LinkList &L)
{//ð������
	char m[20];
	int i,j;
	int flag=1;
	for(i=0;i<L.length-1 && flag;i++)
	{
		flag=0;
		for(j=0;j<L.length-i-1;j++)
			if(strcmp(L.elem[j],L.elem[j+1])>0)
			{
				strcpy(m,L.elem[j]);
				strcpy(L.elem[j],L.elem[j+1]);
				strcpy(L.elem[j+1],m);
				flag=1;
			}
	}
}

void Binsrch(LinkList &L,char *a)
{
	int low,high,mid;
	int flag=1;
	low=0;
	high=L.length-1;
	while(low<=high&&flag)
	{
	    mid=(low+high)/2;
		if(strcmp(a,L.elem[mid])==0)
		{
			printf("��Ҫ���ҵĳ��ƺ��ǵ�%d����\n",mid+1);
			flag=0;
		}
		else if(strcmp(a,L.elem[mid])>0)
		{
			low=mid+1;
			mid=(low+high)/2;
		}
		else
		{
			high=mid-1;
			mid=(low+high)/2;
		}
	}
	if(flag)
		printf("��Ҫ���ҵĳ��ƺŲ����ڡ�\n");
}

void Output(LinkList &L)
{
    int i;
    for(i=1;i<=L.length;i++)
      printf("%s\n",L.elem[i]);
}

int main()
{
    LinkList L;
	char c[20];
    Iuput(L);
    BubbleSort(L);
	printf("����ź���ĳ��ƺ�:\n");
	Output(L);
	printf("����Ҫ���ҵĳ��ƺ�:\n");
	Binsrch(L,*c);
}
