package 逯其鲁20142203713;

import java.util.Scanner;
import java.util.regex.Pattern;

public class PasswordCheck {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner cin=new Scanner(System.in);
		String str1="[0-9a-zA-Z]{8,16}";
		String str2=".*\\d.*\\d.*";
		String password;
		while(cin.hasNext())
		{
			password=cin.next();
			if(Pattern.matches(str1,password) && Pattern.matches(str2,password))
				System.out.println("valid password");
			else
				System.out.println("Invalid password");
			
		}
	}

}
