package 第四章课后题;
import java.util.*;			

public class Problem15 {
	
	public static void main(String[] args) {
		int A[]={1,7,9,11,13,15,17,19};
		int B[]={2,4,6,8,10};
		int[] C=new int[A.length+B.length];
		int i=0,m=0,n=0;
		while (m<A.length&&n<B.length)
		{
			if (A[m]<B[n])
				C[i++]=A[m++];
			else
				C[i++]=B[n++];
		}
		while (m<A.length)
			C[i++]=A[m++];
		while (n<B.length)
			C[i++]=B[n++];
		int k;
		for (k=0;k<i;k++)
			System.out.println(C[k]);
	}

}
