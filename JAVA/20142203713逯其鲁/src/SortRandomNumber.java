import java.math.*;
import java.util.*;
public class SortRandomNumber {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
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
			System.out.println("\n" + "δ�ҵ�����55��");
		else
			System.out.println("\n" + "����55�ǵ�"+index+"�����֡�");
	}
}