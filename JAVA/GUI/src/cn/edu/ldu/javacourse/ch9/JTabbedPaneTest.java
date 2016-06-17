package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
public class JTabbedPaneTest extends JFrame{
	private JTabbedPane jtabbedpane = new JTabbedPane();
	private JTextField jtextField = new JTextField();
	public JTabbedPaneTest(String title){
		super(title);
		Container contentPane = this.getContentPane();
		//�������ѡ�
		jtabbedpane.addTab("��һҳ",  new  JPanel());
		jtabbedpane.addTab("�ڶ�ҳ",  new JPanel());
		jtabbedpane.addTab("����ҳ",  new  JPanel());
		jtabbedpane.addTab("����ҳ",  new JPanel());
		jtabbedpane.addTab("����ҳ",  new  JPanel());
		jtabbedpane.addTab("����ҳ",  new JPanel());
		//ע�������
		jtabbedpane.addChangeListener(new MyChangeListener());
		contentPane.add(jtextField,BorderLayout.SOUTH);
		contentPane.add(jtabbedpane,BorderLayout.CENTER);
		this.setSize(300,200);
		this.setVisible(true);
	}
	//�����ڲ��ദ��Change�¼�
	private class MyChangeListener implements ChangeListener{
		public void stateChanged(ChangeEvent e) {
			String temp = jtabbedpane.getTitleAt(jtabbedpane.getSelectedIndex());
			jtextField.setText(temp+"��ѡ��");
		}	
	}

	public static void main(String[] args) {
		new JTabbedPaneTest("JTabbedPane����");
	}
}

