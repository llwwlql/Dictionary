package use_list;

import java.awt.Dimension;
import java.awt.List;
import java.util.ArrayList;
import java.util.Scanner;

public class UseList {
	
	public void testadd(){
		Scanner cin = new Scanner(System.in);
		ArrayList<Integer> list=new ArrayList<Integer>();
		System.out.println("请输入十个数字:");
		for(int i=0;i<10;i++)
		{
			lst.add(null, cin.nextInt());
		}
		for(int i=10;i>=0;i--)
		{
			System.out.println(lst[i]);
		}
	}
}
