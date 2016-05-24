#include<stdio.h>  
#include<string.h>  
int main()  
{  
    char a1[1100],b1[1100];  
    int    T;  
    while(scanf("%d",&T)!=EOF)  
    {  
        int i1,i,j,k,k1,La,Lb,t,L;  
        for(i1=1;i1<=T;i1++)  
        {  
            int a[1100]={0},b[1100]={0},c[1100]={0};  
            scanf("%s%s",&a1,&b1);  
            La=strlen(a1);  
            Lb=strlen(b1);  
            printf("Case %d:\n",i1);  
            for(i=0;i<La;i++) 
            {  
                printf("%c",a1[i]);  
            }  
            printf(" + ");  
            for(i=0;i<Lb;i++) 
            {  
                printf("%c",b1[i]);  
            }  
            printf(" = ");  
            for(j=La-1,t=0;j>=0;j--,t++)  
            {  
                a[t]=a1[j]-'0';  
            }  
            for(k=Lb-1,t=0;k>=0;k--,t++)  
            {  
                b[t]=b1[k]-'0';  
            }  
            L=(La>=Lb?La:Lb);  
           for(i=0;i<=L-1;i++)  
           {  
               c[i]=(a[i]+b[i])+c[i];  
               if(c[i]>=10)  
               {  
                   c[i]=c[i]%10;  
                   c[i+1]++;  
               }  
           }  
           if(c[L]!=0)  
           {  
               L++;  
           }  
           for(i=L-1;i>=0;i--)  
           {  
               printf("%d",c[i]);  
           }  
           printf("\n");  
           if(i1!=T)  
           {  
               printf("\n");  
           }  
        }  
    }  
    return 0;  
} 
