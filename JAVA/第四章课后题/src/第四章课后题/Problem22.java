package 第四章课后题;

import java.util.*;
public class Problem22 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		String str=cin.nextLine();
		char[] ch;
		int len,count=0,temp,j,i;
		len=str.length();
		ch=str.toCharArray();		//用字符串读入，转换成char数组
		if(len>=13 && len<=16)		//判断长度是否符合
		{
			for(i=len-1,j=1;i>=0;i--,j++)	//i控制循环，j用来表示奇偶位
			{
				if(j%2==0)					//temp记录当前奇偶位应该相加的值
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
			System.out.println("成功。\n");
		else
			System.out.println("失败。\n");
	}
}