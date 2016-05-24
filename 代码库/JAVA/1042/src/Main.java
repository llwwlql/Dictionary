import java.math.BigInteger;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i,n;
		BigInteger Sum,ad,temp;
		Scanner cin= new Scanner(System.in);
		while(cin.hasNext())
		{
			n=cin.nextInt();
			Sum=new BigInteger("1");
			ad=new BigInteger("1");
			temp=new BigInteger("1");
			for(i=2;i<=n;i++)
			{
				ad=ad.add(temp);
				Sum=Sum.multiply(ad);
			}
			System.out.println(Sum);
		}
	}	
}
