package �����¿κ���;

import java.util.Scanner;
import java.util.regex.Pattern;
public class Problem17 {
	public static void main(String[] args){
		String str_1="[a-z]";
		String str_2="[A-Z]";
		String str_3="[0-9]";
		Scanner input=new Scanner(System.in);
		while(true){
			System.out.println("������һ���ַ�:");
			String str=input.next();
			if(Pattern.matches(str_1,str)){
				System.out.println("����һ��Сд��ĸ��");
			}	
			else if(Pattern.matches(str_2,str)){
				System.out.println("����һ����д��ĸ��");
			}
			else if(Pattern.matches(str_3,str)){
				System.out.println("����һ�����֡�");
			}
			else{
				System.out.println("�Ȳ�����ĸҲ�������֡�");
			}
		}
	}
}