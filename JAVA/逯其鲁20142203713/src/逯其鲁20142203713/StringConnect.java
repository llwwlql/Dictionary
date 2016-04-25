package 逯其鲁20142203713;

public class StringConnect {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
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
		System.out.println("字符串的长度为： "+str1.length());
		System.out.println("字符串中的大写字母个数为： "+count);
	}
}
