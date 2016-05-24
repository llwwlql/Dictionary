package TestComputeTotalSales;

public class Shop {
	ComputeTotalSales[] c =new ComputeTotalSales[3];
	
	public Shop() {
		// TODO 自动生成的构造函数存根
		c[0]=new Television();
		c[1]=new Mobile();
		c[2]=new Computer();
	}	
	public void totalsales()
	{
		System.out.println("电视的销售额为：" + c[0].totalSalesByYear());
		System.out.println("手机的销售额为：" + c[1].totalSalesByYear());
		System.out.println("电脑的销售额为：" + c[2].totalSalesByYear());
		System.out.println("电视，电脑，手机的总销售额为：" +(c[0].totalSalesByYear() + c[1].totalSalesByYear() + c[2].totalSalesByYear()));
	}
}