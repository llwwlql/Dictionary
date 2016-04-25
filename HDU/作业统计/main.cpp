#include "Student.h"
#include "S_Number.h"
#include <stdio.h>
#include <stdlib.h>

S_Number studentcount;

void Match()
{
    FILE *fa,*fb,*fout;     //fout�����ĵ�
    fa=fopen("cache/LIST.txt","r");
    fout=fopen("Count/count.txt","w+");
    if(!fa)
    {
        printf("�ļ���ȡʧ�ܣ�");
        exit(0);
    }
    fb=fopen("cache/ID.txt","r");
    if(!fb)
    {
        printf("�ļ���ȡʧ�ܣ�");
        exit(0);
    }
    if(studentcount.get_studentcount()==0)
    {//���ûͳ�ƹ�ѧ��������ͳ��ѧ������
        char ch[100];
        while(!feof(fb))                    //��ȡ��������
        {
            fgets(ch,256,fb);
            studentcount.add_studentcount(1);
        }

        studentcount.sub_studentcount(1);       //����ʹ��,�˴�Ҫ���ĵ�������޻س�

        fb=fopen("cache/ID.txt","r");
        if(!fb)
        {
            printf("�ļ���ȡʧ�ܣ�");
            exit(0);
        }
    }
    Student *stu=new Student[studentcount.get_studentcount()];
    for(int i=0;i<studentcount.get_studentcount();i++)
    {//��ȡѧ��ѧ����Ϣ���ύ������Ϣ
        char ID[20];
        fscanf(fb,"%s",ID);
        stu[i].set_ID(ID);
        stu[i].set_count(0);
    }

    while(!feof(fa))
    {//��ȡ�ļ����е�ѧ�Ž���ƥ��
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

    //��ȡ�ύ��ҵ���ļ����ַ���
}

int main()
{
    system("DIR *.* /B/S> cache/LIST.txt");    //DIR�ҵ�ָ��Ŀ¼��
    Match();
    system("pause");
    return 0;
}
