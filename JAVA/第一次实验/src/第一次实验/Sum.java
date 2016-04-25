package 第一次实验;

public class Sum {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int i=1;
		while(i<=1000)
		{
			if(i%3==0 && i%7==0)
				System.out.print(i+" ");
			i++;
		}
	}
}
