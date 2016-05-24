#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Insertion_Sort(int *a,int lenth)
{
    int key,i,j;
    for(i=2;i<=lenth;i++)
    {
        key=a[i];
        for(j=i-1;j>0 && key<a[j];j--)
            a[j+1]=a[j];
        a[j+1]=key;
    }
}
void display(int *a,int lenth)
{
    int i;
    for(i=1;i<=lenth;i++)
    {
        cout<<a[i]<<' ';
        if(i%10==0)
            cout<<endl;
    }
}

int main()
{
    int a[1005];
    srand(time(0));
    int i,j,n;
    cout<<"输入数据个数\n";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        a[i]=rand()%101;
        cout<<a[i]<<' ';
        if(i%10==0)
            cout<<endl;
    }
    Insertion_Sort(a,n);
    display(a,n);

    return 0;
}
