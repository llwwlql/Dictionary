package �����¿κ���;
//�����µ�9��
import java.util.Scanner;

public class Function {
	double a,b,c;
	public Function(double a,double b,double c){
		this.a=a;
		this.b=b;
		this.c=c;
	}
	public double coputeRoot(){
		double m,n;
		m=b*b-4*a*c;
		if(a==0){
			System.out.println("������ϵ������Ϊ�㣡");
			return 0;
		}else if(m<0){
			System.out.println("�޽�");
			return 0;
		}
		n=Math.sqrt(m);
		double r1=(-b+n)/2*a;
		double r2=(-b-n)/2*a;
		System.out.println("���Ϊ��"+r1+"  "+r2);
		return 0;
	}
	public static void main(String[] args){
		Function f=new Function(2,6,1);
		f.coputeRoot();
	}
}
