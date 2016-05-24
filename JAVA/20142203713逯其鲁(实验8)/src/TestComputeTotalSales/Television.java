package TestComputeTotalSales;

public class Television implements ComputeTotalSales{
	double salesByYear;
	public Television() {
		// TODO 自动生成的构造函数存根
		this.salesByYear=25000.0;
	}
	@Override
	public double totalSalesByYear() {
		// TODO 自动生成的方法存根
		return this.salesByYear;		
	}
}
