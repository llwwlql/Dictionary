package TestComputeTotalSales;

public class Computer implements ComputeTotalSales {
	
	double salesByYear;
	public Computer() {
		// TODO �Զ����ɵĹ��캯�����
		this.salesByYear=35000.0;
	}
	
	public double totalSalesByYear() {
		// TODO �Զ����ɵķ������
		return this.salesByYear;
	}
}