package 第一次实验;

public class SumEight {
	
	public static void main(String[] args) {
		int i;
		long n=8,sum=0;
		for(i=1;i<=10;i++)
		{
			sum+=n;
			n=n*10+8;
		}
		System.out.println(sum);
	}
	
}
