package Compute_earnings;

public class HardWorker {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Employee[] e=new Employee[3];
		e[0]=new YearWorker();
		e[1]=new MonthWorker();
		e[2]=new WeakWorker();
		System.out.println("一年需要支付的薪水总额："+(e[0].earnings()+e[1].earnings()+e[2].earnings())+" RMB");		
	}
}