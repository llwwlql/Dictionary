package PirrarTest;

public class Rectangle extends Geometry{
	double length,weight;
	public Rectangle() {
		// TODO 自动生成的构造函数存根
		this.length=5.3;
		this.weight=3.4;
	}
	public double getArea() {
		// TODO 自动生成的方法存根
		return this.length*this.weight;
	}
}
