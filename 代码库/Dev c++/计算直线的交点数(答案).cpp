#include<stdio.h>
#include<string.h>
const int MAXN=305;
int main()
{
    int n,i,j,k;
    int line[30][MAXN];
    memset(line[1], 0, sizeof(line[1]));
    line[1][0]=1;
    for (i=2; i<=20; i++)    //计算当直线个数为i时的交点情况
    {
        memset(line[i], 0, sizeof(line[i]));
        line[i][0]=1;    //无论有几条直线，都会存在交点个数为0的这种情况
        for (j=1; j<i; j++)    //对i条直线进行划分
        {
            for (k=0; k<MAXN; k++)    //计算该种划分情况下，交点的个数
            {
                if (line[j][k]==1)
                {
                    line[i][(i-j)*j+k]=1;    //line[i][(i-j)*j+k]=1表示存在交点个数为(i-j)*j+k
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
