package PirrarTest;

public class Rectangle extends Geometry{
	double length,weight;
	public Rectangle() {
		// TODO �Զ����ɵĹ��캯�����
		this.length=5.3;
		this.weight=3.4;
	}
	public double getArea() {
		// TODO �Զ����ɵķ������
		return this.length*this.weight;
	}
}
