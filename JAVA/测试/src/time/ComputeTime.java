package time;

import java.lang.reflect.Method;

public class ComputeTime {
        /*public double compute(Common c)
        {
        	return 1000/c.speed();
        }*/
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		double a,b,c;
		double speed;
		ComputeTime com=new ComputeTime();
		Common c1=(Common)Class.forName(args[0]).newInstance();
		a=Integer.parseInt(args[1]);
		b=Integer.parseInt(args[2]);
		c=Integer.parseInt(args[3]);
		speed=c1.speed(a,b,c);
		System.out.println(1000/speed);
	}

}
