package 第四章课后题;
import java.util.regex.Pattern;
import java.util.Scanner;
public class Problem18{
	public static void main(String[] args) {
		String str_1="[a-zA-Z0-9]{8,16}";  //密码只能包含字母和数字,密码长度在 8-16 之间
		String str_2=".*\\d.*\\d.*";  //密码必须存在至少 2 个数字
		Scanner input=new Scanner(System.in);
		System.out.println("请输入密码:");
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
