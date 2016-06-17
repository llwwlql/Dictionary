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
		//添加六个选项卡
		jtabbedpane.addTab("第一页",  new  JPanel());
		jtabbedpane.addTab("第二页",  new JPanel());
		jtabbedpane.addTab("第三页",  new  JPanel());
		jtabbedpane.addTab("第四页",  new JPanel());
		jtabbedpane.addTab("第五页",  new  JPanel());
		jtabbedpane.addTab("第六页",  new JPanel());
		//注册监听器
		jtabbedpane.addChangeListener(new MyChangeListener());
		contentPane.add(jtextField,BorderLayout.SOUTH);
		contentPane.add(jtabbedpane,BorderLayout.CENTER);
		this.setSize(300,200);
		this.setVisible(true);
	}
	//命名内部类处理Change事件
	private class MyChangeListener implements ChangeListener{
		public void stateChanged(ChangeEvent e) {
			String temp = jtabbedpane.getTitleAt(jtabbedpane.getSelectedIndex());
			jtextField.setText(temp+"被选择");
		}	
	}

	public static void main(String[] args) {
		new JTabbedPaneTest("JTabbedPane测试");
	}
}

