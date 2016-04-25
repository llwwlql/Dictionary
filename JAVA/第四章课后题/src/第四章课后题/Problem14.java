package 第四章课后题;
import java.util.*;			

public class Problem14 {
	
	public static void main(String[] args) {
		int oldarr[]={1,3,4,5,0,0,6,6,0,5,4,7,6,7,0,5};
		int[] newarr=new int[oldarr.length];
	     int i,k=0;
	     for (i=0;i<oldarr.length;i++)
	    	 if (oldarr[i]!=0)
	    	    newarr[k++]=oldarr[i];
	     for (i=0;i<k;i++)
	    	 System.out.println(newarr[i]);
	}
}
