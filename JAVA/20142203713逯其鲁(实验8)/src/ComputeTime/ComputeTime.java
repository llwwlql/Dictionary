package ComputeTime;

public class ComputeTime {
	
	public static double computetime(Common c)
	{	
		return 1000.0/c.speed();
	}

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Car c=new Car(10.0,20.0,30.0);
		Plane p=new Plane(10.0,20.0,30.0);
		
		System.out.println("汽车跑1000公里需要的时间为："+computetime(c)+"分钟");
		System.out.println("飞机飞1000公里需要的时间为："+computetime(p)+"分钟");
		
	}

}
