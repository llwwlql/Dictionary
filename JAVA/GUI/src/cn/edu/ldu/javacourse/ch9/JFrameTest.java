package cn.edu.ldu.javacourse.ch9;

import javax.swing.*;
import java.awt.*;

public class JFrameTest extends JFrame {
	private JButton button1 = new JButton("button1");
	private JButton button2 = new JButton("button2");

	public JFrameTest(String title) {
		super(title);
		this.setBounds(50, 50, 200, 150);
		
//		Container contentPane = this.getContentPane();
//		
//		contentPane.setLayout(new FlowLayout(5));
//		contentPane.add(button1);
//		contentPane.add(button2);
		setLayout(new FlowLayout(5));
		this.add(button1);
		this.add(button2);
		this.setVisible(true);
	
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String[] args) {
		new JFrameTest("JFrame≤‚ ‘");
	}
}
