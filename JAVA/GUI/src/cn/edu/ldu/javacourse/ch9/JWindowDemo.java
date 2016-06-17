package cn.edu.ldu.javacourse.ch9;

import javax.swing.JButton;
import javax.swing.JWindow;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.*;

public class JWindowDemo extends JWindow {

	private int X = 0;
	private int Y = 0;

	public JWindowDemo() {
		setBounds(60, 60, 300, 300);
		this.setBackground(Color.BLUE);

		addWindowListener(new WindowAdapter() {

			public void windowClosing(WindowEvent e) {
				System.out.println("closing....");
				System.exit(0); // An Exit Listener
			}
		});
		this.getContentPane().setLayout(new FlowLayout(2));
		JButton button2 = new JButton("button2");
		button2.setSize(50, 50);
		this.getContentPane().add(button2);
		setVisible(true);
	}

	public static void main(String[] args) {
		new JWindowDemo();
	}
}
