package PirrarTest;

public class PirrarTest {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根		
		Geometry c=new Circle();
		Geometry t=new Triangle();
		Geometry r=new Rectangle();
		Pirrar p=new Pirrar();
		p.bottom=c;
		p.height=10;
		System.out.println("圆柱体体积："+p.getVolume());
		p.bottom=t;
		System.out.println("三棱柱的体积："+p.getVolume());
		p.bottom=r;
		System.out.println("长方体的体积："+p.getVolume());
	}
}
