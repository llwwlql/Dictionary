#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
const int NUM=10000;
using namespace std;
void Merge(int *A,int p,int q,int r)
{
    int n1,n2;
    int *L,*R,i,j,k;
    n1=q-p+1;
    n2=r-q;
    L=new int[n1+2];
    R=new int[n2+2];
    for(i=1;i<=n1;i++)
        L[i]=A[p+i-1];
    for(j=1;j<=n2;j++)
        R[j]=A[q+j];
    L[n1+1]=NUM;
    R[n2+1]=NUM;
    i=j=1;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
}

void Merge_Sort(int *A,int p,int r)
{
    if(p<r)
    {
        int q=floor((p+r)/2);
        Merge_Sort(A,p,q);
        Merge_Sort(A,q+1,r);
        Merge(A,p,q,r);
    }
}
void display(int *A,int lenth)          //
{
    int i,j;
    for(i=1;i<=lenth;i++)
    {
        cout<<A[i]<<' ';
        if(i%10==0)
            cout<<endl;
    }
}

int main()
{
    int A[1005];
    int n,i,j;
    srand(time(0));         //生成随机数
    cout<<"输入随机数据个数:\n";
    cin>>n;
    for(i=1;i<=n;i++)
        A[i]=rand()%101;    //产生随机数

    display(A,n);
    cout<<endl;

    Merge_Sort(A,1,n);

    display(A,n);
    return 0;
}
