package PirrarTest;

public class Triangle extends Geometry{
	double side_a,side_b,side_c;

	public Triangle() {
		// TODO �Զ����ɵĹ��캯�����
		this.side_a=3.1;
		this.side_b=4.1;
		this.side_c=5.1;
	}
	public double getArea() {
		// TODO �Զ����ɵķ������
		double p=(this.side_a+this.side_b+this.side_c)/2.0;
		return Math.sqrt(p*(p-this.side_a)*(p-this.side_b)*(p-this.side_c));
	}
}
