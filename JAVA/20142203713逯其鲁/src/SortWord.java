import java.util.*;
public class SortWord {
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		char[] str={'a','d','m','z','h','c','o'};
		Arrays.sort(str);
		System.out.println("The sorted is:");
		for(int i=str.length-1;i>=0;i--)
			System.out.print(str[i]+" ");
	}
}