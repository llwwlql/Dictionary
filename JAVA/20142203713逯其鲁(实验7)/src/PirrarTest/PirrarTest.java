package PirrarTest;

public class PirrarTest {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������		
		Geometry c=new Circle();
		Geometry t=new Triangle();
		Geometry r=new Rectangle();
		Pirrar p=new Pirrar();
		p.bottom=c;
		p.height=10;
		System.out.println("Բ���������"+p.getVolume());
		p.bottom=t;
		System.out.println("�������������"+p.getVolume());
		p.bottom=r;
		System.out.println("������������"+p.getVolume());
	}
}
