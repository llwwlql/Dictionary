package ComputeTime;
public class ComputeTime {
	public static void main(String[] args) throws Exception{
		// TODO 自动生成的方法存根
		double a,b,c;
		double speed;
		Common c1=(Common)Class.forName(args[0]).newInstance();
		a=Integer.parseInt(args[1]);
		b=Integer.parseInt(args[2]);
		c=Integer.parseInt(args[3]);
		speed = a+b-c;
		System.out.println(1000/speed);
	}
}

/*
 * 没有明白题意，没有实现
*/
