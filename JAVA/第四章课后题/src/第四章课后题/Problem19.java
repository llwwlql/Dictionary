package �����¿κ���;

public class Problem19 {
	public static int countLetters(String s)
	{
		int len=s.length(),i,count=0;
		char []ch=s.toCharArray();		//���ַ���ת�����ַ�����
		for (char a:ch)
		{
			if(Character.isLetter(a))	//�ж��Ƿ�Ϊ��ĸ
				count++;
		}
		return count;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s="Hello123213World";
		int countletters=countLetters(s);
		System.out.println("�ַ�������ĸ��ĿΪ��"+countletters);	
	}
}
