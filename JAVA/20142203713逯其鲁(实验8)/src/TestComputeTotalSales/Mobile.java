package TestComputeTotalSales;

public class Mobile implements ComputeTotalSales{
	
	double salesByYear;
	public Mobile() {
		// TODO 自动生成的构造函数存根
		this.salesByYear=20000.0;
	}
	
	public double totalSalesByYear()
	{
		return this.salesByYear;
	}
}