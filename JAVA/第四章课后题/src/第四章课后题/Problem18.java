package �����¿κ���;
import java.util.regex.Pattern;
import java.util.Scanner;
public class Problem18{
	public static void main(String[] args) {
		String str_1="[a-zA-Z0-9]{8,16}";  //����ֻ�ܰ�����ĸ������,���볤���� 8-16 ֮��
		String str_2=".*\\d.*\\d.*";  //�������������� 2 ������
		Scanner input=new Scanner(System.in);
		System.out.println("����������:");
		String password=input.nextLine();
		if(Pattern.matches(str_1,password)&&Pattern.matches(str_2,password))
		{
			System.out.println("valid password");
		}
		else
		{
			System.out.println("Invalid password");
		}
	}
}
