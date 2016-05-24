import java.math.BigInteger;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		BigInteger a,b,sum;
		int T,index;
		T=cin.nextInt();
		index=0;
		while(T>0)
		{
			T--;
			index++;
			a=cin.nextBigInteger();
			b=cin.nextBigInteger();
			sum=a.add(b);
			System.out.println("Case " + index + ":");
			System.out.println(a + " + " + b + " = " + sum);
			if(T!=0)
				System.out.println();
		}
	}
}
