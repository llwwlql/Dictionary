package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CardLayoutDemo implements ActionListener {
	JPanel p1, p2, p3, p4;
	int i = 1;
	JFrame f;

	public CardLayoutDemo() {
		f = new JFrame();// ����top-level���
		Container contentPane = f.getContentPane();
		contentPane.setLayout(new GridLayout(2, 1));

		p1 = new JPanel();
		JButton b = new JButton("Change Card");
		b.addActionListener(this);// ������"Change Card"ʱ�������¼�������������ϵͳ����������
		p1.add(b); // ���������52-64��.
		contentPane.add(p1);

		p2 = new JPanel();
		p2.setLayout(new FlowLayout());
		p2.add(new JButton("first"));
		p2.add(new JButton("second"));
		p2.add(new JButton("third"));

		p3 = new JPanel();
		p3.setLayout(new GridLayout(3, 1));
		p3.add(new JButton("fourth"));
		p3.add(new JButton("fifth"));
		p3.add(new JButton("This is the last button"));

		p4 = new JPanel();
		p4.setLayout(new CardLayout());
		p4.add("one", p2);
		p4.add("two", p3);
		/*
		 * Ҫ��ʾCardLayout�Ŀ�Ƭ��������show(Container parent,String name)���������
		 * ��Ҳ������first(
		 * Container),next(Container),previous(Container),last(Container)��
		 * �ĸ�������һ�����Դﵽ��ʾЧ����
		 */
		((CardLayout) p4.getLayout()).show(p4, "one");

		contentPane.add(p4);

		f.setTitle("CardLayout");
		f.pack();
		f.setVisible(true);

		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});

	}

	public void actionPerformed(ActionEvent event) {
		switch (i) {
		case 1:
			((CardLayout) p4.getLayout()).show(p4, "two");
			break;
		case 2:
			((CardLayout) p4.getLayout()).show(p4, "one");
			break;
		}
		i++;
		if (i == 3)
			i = 1;
		f.validate();
	}

	public static void main(String[] args) {
		new CardLayoutDemo();
	}
}
