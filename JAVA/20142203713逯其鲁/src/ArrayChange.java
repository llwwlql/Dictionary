public class ArrayChange {
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int oldArr[]={1,3,4,5,0,0,6,6,0,5,4,7,6,7,0,5};
		int newArr[]=new int[oldArr.length];
		int newlen=0;
		for(int i=0;i<oldArr.length;i++)
			if(oldArr[i]!=0)
				newArr[newlen++]=oldArr[i];
		for(int i=0;i<newlen;i++)
			System.out.println(newArr[i]);	
	}
}