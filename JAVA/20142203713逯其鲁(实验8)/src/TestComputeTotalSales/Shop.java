package TestComputeTotalSales;

public class Shop {
	ComputeTotalSales[] c =new ComputeTotalSales[3];
	
	public Shop() {
		// TODO �Զ����ɵĹ��캯�����
		c[0]=new Television();
		c[1]=new Mobile();
		c[2]=new Computer();
	}	
	public void totalsales()
	{
		System.out.println("���ӵ����۶�Ϊ��" + c[0].totalSalesByYear());
		System.out.println("�ֻ������۶�Ϊ��" + c[1].totalSalesByYear());
		System.out.println("���Ե����۶�Ϊ��" + c[2].totalSalesByYear());
		System.out.println("���ӣ����ԣ��ֻ��������۶�Ϊ��" +(c[0].totalSalesByYear() + c[1].totalSalesByYear() + c[2].totalSalesByYear()));
	}
}