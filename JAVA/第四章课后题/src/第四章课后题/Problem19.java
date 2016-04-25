package 第四章课后题;

public class Problem19 {
	public static int countLetters(String s)
	{
		int len=s.length(),i,count=0;
		char []ch=s.toCharArray();		//将字符串转换成字符数组
		for (char a:ch)
		{
			if(Character.isLetter(a))	//判断是否为字母
				count++;
		}
		return count;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s="Hello123213World";
		int countletters=countLetters(s);
		System.out.println("字符串中字母数目为："+countletters);	
	}
}
