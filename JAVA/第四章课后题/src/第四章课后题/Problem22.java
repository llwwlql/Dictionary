package �����¿κ���;

import java.util.*;
public class Problem22 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		String str=cin.nextLine();
		char[] ch;
		int len,count=0,temp,j,i;
		len=str.length();
		ch=str.toCharArray();		//���ַ������룬ת����char����
		if(len>=13 && len<=16)		//�жϳ����Ƿ����
		{
			for(i=len-1,j=1;i>=0;i--,j++)	//i����ѭ����j������ʾ��żλ
			{
				if(j%2==0)					//temp��¼��ǰ��żλӦ����ӵ�ֵ
				{
					temp=(ch[i]-'0')*2;
					if(temp>=10)
						temp-=9;
				}
				else
					temp=ch[i]-'0';
				count+=temp;
			}
		}
		else
			count=-1;
		if(count%10==0)
			System.out.println("�ɹ���\n");
		else
			System.out.println("ʧ�ܡ�\n");
	}
}