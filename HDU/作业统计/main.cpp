#include "Student.h"
#include "S_Number.h"
#include <stdio.h>
#include <stdlib.h>

S_Number studentcount;

void Match()
{
    FILE *fa,*fb,*fout;     //fout测试文档
    fa=fopen("cache/LIST.txt","r");
    fout=fopen("Count/count.txt","w+");
    if(!fa)
    {
        printf("文件读取失败！");
        exit(0);
    }
    fb=fopen("cache/ID.txt","r");
    if(!fb)
    {
        printf("文件读取失败！");
        exit(0);
    }
    if(studentcount.get_studentcount()==0)
    {//如果没统计过学生人数，统计学生人数
        char ch[100];
        while(!feof(fb))                    //读取文章行数
        {
            fgets(ch,256,fb);
            studentcount.add_studentcount(1);
        }

        studentcount.sub_studentcount(1);       //测试使用,此处要看文档最后有无回车

        fb=fopen("cache/ID.txt","r");
        if(!fb)
        {
            printf("文件读取失败！");
            exit(0);
        }
    }
    Student *stu=new Student[studentcount.get_studentcount()];
    for(int i=0;i<studentcount.get_studentcount();i++)
    {//读取学生学号信息及提交次数信息
        char ID[20];
        fscanf(fb,"%s",ID);
        stu[i].set_ID(ID);
        stu[i].set_count(0);
    }

    while(!feof(fa))
    {//读取文件名中的学号进行匹配
        int i,j,len;
        char str[150],ID[20];
        fscanf(fa,"%s",str);
        len=strlen(str);
        for(i=0;!(str[i]>='0' && str[i]<='9') && i<len;i++);
        for(j=i;j<=len && str[j]>='0' && str[j]<='9';j++)
            ID[j-i]=str[j];
        ID[j-i]='\0';

        for(i=0;i<studentcount.get_studentcount();i++)
        {
            if(strcmp(stu[i].get_ID(),ID)==0)
            {
                stu[i].add_count();
                break;
            }
        }
    }

    for(int i=0;i<studentcount.get_studentcount();i++)
        fprintf(fout,"%d\n",stu[i].get_count());

    fclose(fa);
    fclose(fb);
    fclose(fout);

    //读取提交作业的文件名字符串
}

int main()
{
    system("DIR *.* /B/S> cache/LIST.txt");    //DIR找到指定目录上
    Match();
    system("pause");
    return 0;
}
