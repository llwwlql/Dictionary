package Compute_earnings;

public class WeakWorker extends Employee{
	double earn=3500;
	@Override
	public double earnings() {
		// TODO �Զ����ɵķ������
		return (365.0/7)*earn;
	}
}
