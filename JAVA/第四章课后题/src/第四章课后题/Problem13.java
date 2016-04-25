package 第四章课后题;
import java.util.Scanner;

public class Problem13 {
	public static void main(String[] args) {
		int[] a;
		int number;
		Scanner in = new Scanner(System.in);
		System.out.println("请输入要输入的数据的个数");
		number = in.nextInt();
		a = new int[number];
		for(int i=0;i<number;i++)
			a[i]= in.nextInt();
		int min=0;
		for(int i=0;i<number;i++)
			if(a[min]>a[i])
				min=i;
		System.out.println(min);
	}
}
