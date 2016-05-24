#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m,l,r,k;
    int i,j;
    unsigned int a[1005];
    unsigned int b[1005];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",a+i);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&l,&r,&k);
        for(i=l;i<=r;i++)
            b[i-l+1]=a[i];
        sort(b,b+r-l+1,cmp);
        printf("%d\n",b[k]);
    }
    return 0;
}
