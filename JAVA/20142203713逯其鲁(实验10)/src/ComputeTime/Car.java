package ComputeTime;

public class Car implements Common{
	double A,B,C;
	
	public Car(double a,double b,double c)
	{
		this.A=a;
		this.B=b;
		this.C=c;
	}
	
	public double speed() {
		// TODO �Զ����ɵķ������
		return A*B/C;
	}
}
