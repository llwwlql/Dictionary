package cn.edu.ldu.javacourse.ch9;

import java.awt.BorderLayout;

import javax.swing.*;

public class ButtonDir {
	public static void main(String args[]) {
		JFrame f = new JFrame("BorderLayout");
		f.setLayout(new BorderLayout());
		f.add("North", new JButton("North"));
		// ��һ��������ʾ�Ѱ�ť��ӵ�������North����
		f.add("South", new JButton("South"));
		f.add("East", new JButton("East"));
		f.add("West", new JButton("West"));
		f.add("Center", new JButton("Center"));
		f.setSize(200, 200);
		f.setVisible(true);
	}
}
