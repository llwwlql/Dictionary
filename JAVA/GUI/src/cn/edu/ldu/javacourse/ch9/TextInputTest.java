package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class TextInputTest extends JFrame{
	private JTextField userName = new JTextField(10);
	private JTextArea ta = new JTextArea(4,10);
	private JPasswordField password = new JPasswordField(10);
	private JLabel label1 = new JLabel("�û���");
	private JLabel label2 = new JLabel("��  ��");
	public TextInputTest(String title){
		super(title);
		password.setEchoChar('*');//���û����ַ�
		Container contentPane = this.getContentPane();
		JPanel panelNorth = new JPanel();
		JPanel panelCenter = new JPanel();
		panelNorth.add(label1);
		panelNorth.add(userName);
		panelCenter.add(label2);
		panelCenter.add(password);
		
		contentPane.add(panelNorth,BorderLayout.NORTH);
		contentPane.add(panelCenter,BorderLayout.CENTER);
		contentPane.add(ta,BorderLayout.SOUTH);
		pack();
		//����userName��password�ؼ�
		userName.addActionListener(new MyActionListener());
		password.addActionListener(new MyActionListener());
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	private class MyActionListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			String name = userName.getText();
			char[] pwd = password.getPassword();
			if(name.length()==0){
				ta.setText("�������û���");
				return;
			}
			if(pwd.length==0){
				ta.setText("����������");
				return;
			}
			//new String(pwd)���ַ�����pwdת��Ϊ�ַ���
			ta.setText("�û�����"+name+"\n���룺"+new String(pwd));	
		}		
	}

	public static void main(String[] args) {
		new TextInputTest("�ı�����ؼ�����");
	}
}
