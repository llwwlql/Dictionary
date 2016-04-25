package 第四章课后题;

import java.util.Arrays;

public class Problem11 {
	public static void main(String[] args) {
		int [] array ={1,2,5,7,9,11,13,15,17,19,};
		for(int i=0;i<array.length/2;i++)
		{
			int temp=array[i];
			array[i]=array[array.length-i-1];
			array[array.length-i-1]=temp;
		}
		
		for(int i=0;i<array.length;i++)
			System.out.print(array[i]+" ");
	}
}
