package ����³20142203713;

public class StringConnect {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		StringBuffer str1=new StringBuffer("Words:");
		char ch;
		int count=0;
		for(int i=1;i<=6;i++)
		{
			ch=(char) (Math.random()*100);
			str1.append(ch);
			Character.isAlphabetic(ch);
			if(Character.isUpperCase(ch))
				count++;
		}
		System.out.println(str1);
		System.out.println("�ַ����ĳ���Ϊ�� "+str1.length());
		System.out.println("�ַ����еĴ�д��ĸ����Ϊ�� "+count);
	}
}
