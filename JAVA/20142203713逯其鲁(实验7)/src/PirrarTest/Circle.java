package PirrarTest;

public class Circle extends Geometry {
	double ridious;
	public Circle()
	{
		this.ridious=4.5;
	}
	
	public double getArea() {
		// TODO �Զ����ɵķ������
		return Math.PI*this.ridious*this.ridious;
	}
}
