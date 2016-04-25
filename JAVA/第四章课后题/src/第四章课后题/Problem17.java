package 第四章课后题;

import java.util.Scanner;
import java.util.regex.Pattern;
public class Problem17 {
	public static void main(String[] args){
		String str_1="[a-z]";
		String str_2="[A-Z]";
		String str_3="[0-9]";
		Scanner input=new Scanner(System.in);
		while(true){
			System.out.println("请输入一个字符:");
			String str=input.next();
			if(Pattern.matches(str_1,str)){
				System.out.println("这是一个小写字母。");
			}	
			else if(Pattern.matches(str_2,str)){
				System.out.println("这是一个大写字母。");
			}
			else if(Pattern.matches(str_3,str)){
				System.out.println("这是一个数字。");
			}
			else{
				System.out.println("既不是字母也不是数字。");
			}
		}
	}
}