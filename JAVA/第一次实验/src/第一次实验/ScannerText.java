package 第一次实验;
import java.util.*;
import java.math.*;
public class ScannerText {
	double _high;
	double _area,_volume,_radius;
	
	public static void main(String args[]){
		ScannerText S=new ScannerText();
		Scanner cin=new Scanner(System.in);
		System.out.println("Please input high and radius:");
		S._high=cin.nextDouble();
		S._radius=cin.nextDouble();
		S._area=Math.PI*S._radius*S._radius;
		S._volume=S._area*S._high;
		System.out.println("The volume is:" + S._volume);
	}

}
