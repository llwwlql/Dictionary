

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class EventHandlingDemo extends JFrame implements ActionListener,
		KeyListener {
	JTextField t1 = new JTextField(15);
	JTextField t2 = new JTextField(15);
	JButton b1 = new JButton("按钮");

	public void init() {
		JLabel l1 = new JLabel("输入：");
		JLabel l2 = new JLabel("输出：");

		setSize(220, 220);
		setTitle("Item Event");
		setLayout(new FlowLayout(FlowLayout.LEFT));
		t1.addKeyListener(this);
		t1.addActionListener(this);
		b1.addActionListener(this);
		// 让frm当成t1、t2、b1的监听器
		add(l1);
		add(t1);
		add(l2);
		add(t2);
		add(b1);
		setVisible(true);
	}

	public static void main(String args[]) {
		new  EventHandlingDemo().init();
	}

	// 事件发生时的处理操作
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == t1)
			t2.setText("文本框发出动作事件");
		if (e.getSource() == b1)
			t2.setText("按钮发出动作事件");
	}

	@Override
	public void keyPressed(KeyEvent arg0) {
		t2.setText("keyPressed");
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
		t2.setText("keyReleased");
	}

	@Override
	public void keyTyped(KeyEvent arg0) {
		t2.setText("keyTyped");
	}
}
