package 第四章课后题;
import java.util.Scanner;

public class Problem12 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int number=0;
		System.out.println("请输入学生的个数");
		number = in.nextInt();
		in.nextLine();
		Student[] student = new Student[number];
		for(int i=0;i<number;i++)
			student[i]=new Student();
		for(int i=0;i<number;i++)
		{
			System.out.println("请输入第"+ (i+1) +"个同学的姓名");
			student[i].setName(in.nextLine());
			System.out.println("请输入第"+ (i+1) +"个同学的成绩");
			student[i].setGrade(in.nextDouble());
			in.nextLine();
		}
		for(int i=0;i<number;i++)
			for(int j=0;j<number-1;j++)
				if(student[j].getGrade()<student[j+1].getGrade())
				{
					Student temp=student[j+1];
					student[j+1]=student[j];
					student[j]=temp;
				}
		for(int i=0;i<number;i++)
		{
			System.out.println(student[i].getName() + " " + student[i].getGrade());
		}
	}
}

class Student{
	private String name;
	private double grade;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public double getGrade() {
		return grade;
	}
	public void setGrade(double grade) {
		this.grade = grade;
	}
}