package Compute_earnings;

public class WeakWorker extends Employee{
	double earn=3500;
	@Override
	public double earnings() {
		// TODO 自动生成的方法存根
		return (365.0/7)*earn;
	}
}
