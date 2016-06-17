package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class JFileChooserDemo extends JFrame{
	private JLabel label = new JLabel("��ѡ�ļ�·����");
	private JTextField tfFileName = new JTextField(25);
	private JButton btnOpen = new JButton("���");
	public JFileChooserDemo(String title){
		super(title);
		Container contentPane = this.getContentPane();
		contentPane.setLayout(new FlowLayout(5));
		contentPane.add(label);
		contentPane.add(tfFileName);
		contentPane.add(btnOpen);
		pack();
		setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//����btnOpen��ť
		btnOpen.addActionListener(new MyActionListener());
	}
	//Action�¼�����
	private class MyActionListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			JFileChooser fc = new JFileChooser("D:\\javaPro");
			int val = fc.showOpenDialog(null);//�ļ��򿪶Ի���
			if(val==fc.APPROVE_OPTION){//����ѡ���ļ�
				tfFileName.setText(fc.getSelectedFile().toString());
			}
			else{//δ����ѡ���ļ�����ѡ��ȡ����ť
				tfFileName.setText("δѡȡ�ļ�");
			}			
		}		
	}

	public static void main(String[] args) {
		new JFileChooserDemo("JFileChooser����");
	}
}
