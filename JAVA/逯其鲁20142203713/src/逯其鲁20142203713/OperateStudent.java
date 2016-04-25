package 逯其鲁20142203713;

import java.util.Arrays;
import java.util.Scanner;

class Student{
	private String _name;
	private String _number;
	private String _date;
	
	
	public String get_number() {
		return _number;
	}
	public void set_number(String _number) {
		this._number = _number;
	}
	public String get_name() {
		return _name;
	}
	public void set_name(String _name) {
		this._name = _name;
	}
	public String get_date() {
		return _date;
	}
	public void set_date(String _date) {
		this._date = _date;
	}
}

public class OperateStudent {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		
		Scanner cin=new Scanner(System.in);
		String str1="[,,|,]";
		String st;
		int count=0;
		Student[] S=new Student[15];
		while(cin.hasNext())
		{
			st=cin.nextLine();
			String[] temp=st.split(str1);
			S[count]=new Student();
			S[count].set_name(temp[1]);
			S[count].set_number(temp[3]);
			S[count].set_date(temp[4]);
			count++;
		}
		Arrays.sort(S,S.get_number);
		for(int i=0;i<count;i++)
			System.out.println(S[i].get_name()+" "+S[i].get_number()+" "+S[i].get_date());
	}
}
