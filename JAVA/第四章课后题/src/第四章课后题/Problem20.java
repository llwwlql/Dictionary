package 第四章课后题;

import java.util.*;
public class Problem20 {
	public static String binaryToHex(String binaryStr)
	{
		return Long.toHexString(Long.parseLong(binaryStr,2));
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		String str1;
		while(cin.hasNext())
		{
			str1=cin.next();
			String str2=binaryToHex(str1);
			System.out.println(str2);
		}

	}
}