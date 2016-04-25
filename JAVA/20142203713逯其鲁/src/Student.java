
import java.util.*;

public class Student {
	String _name;
	double _score;
	
	public boolean Compare(Student S)
	{
		if(this._score<S._score)
			return true;
		return false;
	}
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int number;
		String name;
		double score;
		Scanner cin=new Scanner(System.in);
		System.out.println("Please input students number:");
		number=cin.nextInt();
		System.out.println("Please input " +number +" students name and score:");
		Student[] S=new Student[number];
		
		for(int i=0;i<number;i++)
		{
			S[i]=new Student();
			S[i]._name=cin.next();
			S[i]._score=cin.nextDouble();
		}
		
		for(int i=0;i<number-1;i++)
		{
			for(int j=i+1;j<number;j++)
			{
				if(S[i].Compare(S[j]))
				{
					Student temp;
					temp=S[i];
					S[i]=S[j];
					S[j]=temp;
				}		
			}
		}
		System.out.println("Sorted:");
		for(int i=0;i<number;i++)
		{
			System.out.println(S[i]._name+ "    " + S[i]._score);
		}
	}
}