#include <iostream>
#include <cstdlib>

using namespace std;

class MyArray{
    int *arry;
    int N;
public:
    MyArray(int n)
    {
        N=n;
        int i;
        arry=(int *)malloc(sizeof(int )*n);
        for(i=0;i<N;i++)
            arry[i]=0;
    }
    ~MyArray()
    {
        delete(arry);
    }
    void input()
    {
        cout<<"pleace input numbers.\n";
        for(int i=0;i<N;i++)
        {
            cin>>arry[i];
        }
    }
    void output()
    {
        int i;
        for(i=0;i<N;i++)
        {
            cout<<arry[i]<<" ";
        }
        cout<<endl;
    }
};

class SortArry:public MyArray{
public:
    void Sort()
    {
        int i,j;
        int temp;
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(arry[i]>arry[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
};

class AverArray:public MyArray{
    float average;
public:
    void Aver()
    {
        average=.0;
        int i;
        for(i=0;i<N;i++)
            average+=arry[i];
        average/=N;
        cout<<"average is "<<average<<endl;
    }
};

int main()
{
    SortArry a;
    AverArray b;
    int n;
    cout<<"pleace input a number(n):";
    cin>>n;
    a.input(n);
    a.Sort();
    a.output();
    b.Aver();

    return 0;
}
