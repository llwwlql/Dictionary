package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class JMenuBarTest extends JFrame{
	private JMenuBar bar = new JMenuBar();
	private JMenu menuFile = new JMenu("文件");
	private JMenuItem itemFile1 = new JMenuItem("新建");
	private JMenuItem itemFile2 = new JMenuItem("打开");
	private JMenuItem itemFile3 = new JMenuItem("保存");
	private JMenuItem itemFile4 = new JMenuItem("退出");
	private JMenu menuHelp = new JMenu("帮助");
	private JMenuItem itemHelp1 = new JMenuItem("帮助主题");
	private JMenuItem itemHelp2 = new JMenuItem("关于记事本");	
	private JTextArea ta = new JTextArea(10,30);
	public JMenuBarTest(String title){
		super(title);
		//设置快捷键
		itemFile1.setAccelerator(KeyStroke.getKeyStroke('N',KeyEvent.CTRL_MASK));
		itemFile2.setAccelerator(KeyStroke.getKeyStroke('O',KeyEvent.CTRL_MASK));
		itemFile3.setAccelerator(KeyStroke.getKeyStroke('S',KeyEvent.CTRL_MASK));
		itemFile4.setAccelerator(KeyStroke.getKeyStroke('E',KeyEvent.CTRL_MASK));
		//添加JMenuItem到JMenu
		menuFile.add(itemFile1);
		menuFile.add(itemFile2);
		menuFile.add(itemFile3);
		menuFile.addSeparator();//加分割线	
		menuFile.add(itemFile4);
		
		menuHelp.add(itemHelp1);
		menuHelp.addSeparator();//加分割线	
		menuHelp.add(itemHelp2);
		//添加JMenu到JBar
		this.setJMenuBar(bar);
		bar.add(menuFile);
		bar.add(menuHelp);
		Container contentPane = this.getContentPane();
		contentPane.add(ta);
		pack();
		this.setVisible(true);	
		//注册监听器
		itemFile1.addActionListener(new MyActionListener());
		itemFile2.addActionListener(new MyActionListener());
		itemFile3.addActionListener(new MyActionListener());
		itemFile4.addActionListener(new MyActionListener());
		itemHelp1.addActionListener(new MyActionListener());
		itemHelp2.addActionListener(new MyActionListener());
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	private class MyActionListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			ta.setText("您按下了菜单项："+e.getActionCommand());			
		}		
	}

	public static void main(String[] args) {
		new JMenuBarTest("记事本");
	}
}
