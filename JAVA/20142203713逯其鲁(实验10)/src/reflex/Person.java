package reflex;

public class Person {
	public String name;
	public int age;
	public char sex;
	public Person() {
		// TODO 自动生成的构造函数存根
	}
	public Person(String name,int age,char sex)
	{
		this.name=name;
		this.age=age;
		this.sex=sex;
	}
	public String toString(){
		return "姓名:"+this.name+"\n年龄:"+this.age+"\n性别:"+this.sex;
	}
	
	public void print()
	{
		System.out.println("Hello World!");
	}

}
