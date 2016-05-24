package 百度之星;
import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner cin= new Scanner(System.in);
		int n;
		int i,j;
		BigInteger[] f=new BigInteger[2005];
		f[1]=new BigInteger("1");
		f[0]=new BigInteger("1");
		for(i=2;i<=200;i++)
		{
			f[i]=f[i-1].add(f[i-2]);
		}
		while(cin.hasNext())
		{
			n=cin.nextInt();
			System.out.println(f[n]);
		}
	}
}
