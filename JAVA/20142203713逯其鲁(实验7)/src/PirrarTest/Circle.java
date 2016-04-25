package PirrarTest;

public class Circle extends Geometry {
	double ridious;
	public Circle()
	{
		this.ridious=4.5;
	}
	
	public double getArea() {
		// TODO 自动生成的方法存根
		return Math.PI*this.ridious*this.ridious;
	}
}
