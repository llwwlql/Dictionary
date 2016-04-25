package PirrarTest;

import java.util.GregorianCalendar;

public class Pirrar {
	double height;
	Geometry bottom;
	public double getVolume(){
		return this.bottom.getArea()*this.height;
	}
}