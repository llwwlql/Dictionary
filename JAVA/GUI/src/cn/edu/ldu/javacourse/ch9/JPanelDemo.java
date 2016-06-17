package cn.edu.ldu.javacourse.ch9;

import javax.swing.*;
import java.awt.*; //引入AWT包，因为要使用到颜色类

public class JPanelDemo {
	public static void main(String[] args) throws Exception {
		JFrame f = new JFrame("第一个Java窗口");
		f.setSize(300, 200);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		f.setVisible(true);
		f.setResizable(false);
		f.setLocationRelativeTo(null);
		
		JPanel p = new JPanel(); 
		
		p.setBackground(Color.BLUE);
		p.setSize(100, 100); // 设置面板对象大小
		f.getContentPane().add(p); 
		
		// f. setContentPane(p);
	}
}
