#include<stdio.h>
#include<string.h>
const int MAXN=305;
int main()
{
    int n,i,j,k;
    int line[30][MAXN];
    memset(line[1], 0, sizeof(line[1]));
    line[1][0]=1;
    for (i=2; i<=20; i++)    //���㵱ֱ�߸���Ϊiʱ�Ľ������
    {
        memset(line[i], 0, sizeof(line[i]));
        line[i][0]=1;    //�����м���ֱ�ߣ�������ڽ������Ϊ0���������
        for (j=1; j<i; j++)    //��i��ֱ�߽��л���
        {
            for (k=0; k<MAXN; k++)    //������ֻ�������£�����ĸ���
            {
                if (line[j][k]==1)
                {
                    line[i][(i-j)*j+k]=1;    //line[i][(i-j)*j+k]=1��ʾ���ڽ������Ϊ(i-j)*j+k
                }
            }
        }
    }
    while (scanf("%d", &n)!=EOF)
    {
        for (i=0; i<MAXN; i++)
        {
            if (i==0) printf("0");
            else if(line[n][i]==1) printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}
