import java.math.BigInteger;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		
		BigInteger f[]=new BigInteger[10005];
		int n;
		f[1]=new BigInteger("1");
		f[2]=new BigInteger("1");
		f[3]=new BigInteger("1");
		f[4]=new BigInteger("1");
		for(int i=5;i<=10000;i++)
			f[i]=f[i-1].add(f[i-2].add(f[i-3].add(f[i-4])));
		
		while(cin.hasNext())
		{
			n=cin.nextInt();
			System.out.println(f[n]);
		}
	}
}
