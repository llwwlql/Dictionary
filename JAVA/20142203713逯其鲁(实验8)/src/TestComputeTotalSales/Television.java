package TestComputeTotalSales;

public class Television implements ComputeTotalSales{
	double salesByYear;
	public Television() {
		// TODO �Զ����ɵĹ��캯�����
		this.salesByYear=25000.0;
	}
	@Override
	public double totalSalesByYear() {
		// TODO �Զ����ɵķ������
		return this.salesByYear;		
	}
}
