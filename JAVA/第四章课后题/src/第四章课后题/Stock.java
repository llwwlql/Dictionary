package 第四章课后题;
//第三章第7题

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
	    System.out.println("从昨日到今天的价格变化为  "+percent);
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
		Stock s=new Stock("PE03DSX","中石油");
		s.setCurrentPrice(96.35);
		s.setPerviousClosingPrice(85.32);
		s.getChangePercent();
	}
}
