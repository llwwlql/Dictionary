package �����¿κ���;
//�����µ�7��

public class Stock {
	String code;
	String name;
	double perviousClosingPrice;
	double currentPrice;
	public Stock(String code,String name){
		this.code=code;
		this.name=name;
	}
	public void getChangePercent(){
		double percent=0;
		percent=(this.currentPrice-this.perviousClosingPrice)/this.currentPrice;
	    System.out.println("�����յ�����ļ۸�仯Ϊ  "+percent);
	}
	public double getPerviousClosingPrice() {
		return perviousClosingPrice;
	}
	public void setPerviousClosingPrice(double perviousClosingPrice) {
		this.perviousClosingPrice = perviousClosingPrice;
	}
	public double getCurrentPrice() {
		return currentPrice;
	}
	public void setCurrentPrice(double currentPrice) {
		this.currentPrice = currentPrice;
	}
	public static void main(String[] args){
		Stock s=new Stock("PE03DSX","��ʯ��");
		s.setCurrentPrice(96.35);
		s.setPerviousClosingPrice(85.32);
		s.getChangePercent();
	}
}
