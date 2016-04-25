package 第四章课后题;

import java.util.*;			

public class Problem16 {
	
	public static void main(String[] args) {
		String str1="Welcome to beijing";
		String str2="welcome to beijing";
	   System.out.println(str1.equals(str2));
		int x;
		x=str1.compareTo(str2);
		System.out.println(x);
		System.out.println(str1.equalsIgnoreCase(str2));
		String str3=str1+str2;
		System.out.println(str3);
		System.out.println(str1.indexOf('e'));
		int len=str2.length();
		System.out.println(len);
		x=str1.lastIndexOf("eij");
		System.out.println(x);
	}
}