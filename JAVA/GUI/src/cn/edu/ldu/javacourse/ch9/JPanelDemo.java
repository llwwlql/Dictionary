package cn.edu.ldu.javacourse.ch9;

import javax.swing.*;
import java.awt.*; //����AWT������ΪҪʹ�õ���ɫ��

public class JPanelDemo {
	public static void main(String[] args) throws Exception {
		JFrame f = new JFrame("��һ��Java����");
		f.setSize(300, 200);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		f.setVisible(true);
		f.setResizable(false);
		f.setLocationRelativeTo(null);
		
		JPanel p = new JPanel(); 
		
		p.setBackground(Color.BLUE);
		p.setSize(100, 100); // �����������С
		f.getContentPane().add(p); 
		
		// f. setContentPane(p);
	}
}
