
import java.util.Scanner;
public class Computeroot {
	     double a;
	     double b;
	     double c;
	  public void computeroot (double a,double b,double c)
	  {
		  double judge;
		  double root,root1;
		  judge=(b*b)-4*a*c;
		  if(judge<0)
		  {
			  System.out.println("方程无实根");
		  }
		  else if(judge==0)
		  {
			  root=(-1.0*b+Math.sqrt(b*b-4*a*c))/(2*a);
			  System.out.println("方程有两个相等的实根："+root);
		  }
		  else 
		  {
			  root=(-1.0*b-Math.sqrt(b*b-4*a*c))/(2*a);
			  root1=(-1.0*b+Math.sqrt(b*b-4*a*c))/(2*a);
			  System.out.println("方程有两个不等的实根："+root+" "+root1);
		  }
	  }
	public static void main(String[] args) {   
		// TODO Auto-generated method stub
         Computeroot c1=new Computeroot ();
         Scanner in=new Scanner(System.in);
         c1.a=in.nextDouble();
         c1.b=in.nextDouble();
         c1.c=in.nextDouble();
         c1.computeroot(c1.a,c1.b,c1.c);
	}

}
