#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Student{
    int a[6];
    float average;
};
struct Sum{
    float average[6];
};
int main()
{
    struct Student stu[55];
    struct Sum sum;
    int i,j;
    int n,m;
    int index,peace;
    while(~scanf("%d %d",&n,&m))
    {
        index=0;
        for(i=0;i<m;i++)
        {
            sum.average[i]=.0;
            stu[i].average=.0;
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&stu[i].a[j]);
                stu[i].average+=stu[i].a[j];
                sum.average[j]+=stu[i].a[j];
            }
            stu[i].average/=m;
        }

        for(i=0;i<m;i++)
            sum.average[i]/=n;


        printf("%.2f",stu[0].average);
        for(i=1;i<n;i++)
            printf(" %.2f",stu[i].average);
        putchar('\n');


        printf("%.2f",sum.average[0]);
        for(i=1;i<m;i++)
            printf(" %.2f",sum.average[i]);
        putchar('\n');


        for(i=0;i<n;i++)
        {
            peace=1;
            for(j=0;j<m && peace;j++)
            {
                if(stu[i].a[j]<sum.average[j])
                    peace=0;
            }
            if(peace)
                index++;
        }
        printf("%d\n\n",index);

    }
    return 0;
}
