import java.math.*;
import java.util.*;
public class SortRandomNumber {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner cin=new Scanner(System.in);
		int n;
		System.out.println("Please input array length :");
		n=cin.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=(int)(Math.random()*100)%200+1;
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		Arrays.sort(arr);
		for(int i=0;i<n;i++)
			System.out.print(arr[i]+" ");
		int index=Arrays.binarySearch(arr, 55);
		if(index<0)
			System.out.println("\n" + "未找到数字55。");
		else
			System.out.println("\n" + "数字55是第"+index+"个数字。");
	}
}