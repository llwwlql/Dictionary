package cn.edu.ldu.javacourse.ch9;

import java.util.EventObject;

public class DirectionEvent extends EventObject {
	public static final int UP_PRESSED = 1;
	public static final int DOWN_PRESSED = 2;
	public static final int LEFT_PRESSED = 3;
	public static final int RIGHT_PRESSED = 4;
	private int direction;
	public DirectionEvent(Object which, int direction) {
		super(which);
		this.setDirection(direction);
	}
	public int getDirection() {
		return direction;
	}
	public void setDirection(int direction) {
		this.direction = direction;
	}
}

