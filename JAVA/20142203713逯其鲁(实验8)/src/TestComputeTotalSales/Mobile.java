package TestComputeTotalSales;

public class Mobile implements ComputeTotalSales{
	
	double salesByYear;
	public Mobile() {
		// TODO �Զ����ɵĹ��캯�����
		this.salesByYear=20000.0;
	}
	
	public double totalSalesByYear()
	{
		return this.salesByYear;
	}
}