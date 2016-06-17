package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class JMenuBarTest extends JFrame{
	private JMenuBar bar = new JMenuBar();
	private JMenu menuFile = new JMenu("�ļ�");
	private JMenuItem itemFile1 = new JMenuItem("�½�");
	private JMenuItem itemFile2 = new JMenuItem("��");
	private JMenuItem itemFile3 = new JMenuItem("����");
	private JMenuItem itemFile4 = new JMenuItem("�˳�");
	private JMenu menuHelp = new JMenu("����");
	private JMenuItem itemHelp1 = new JMenuItem("��������");
	private JMenuItem itemHelp2 = new JMenuItem("���ڼ��±�");	
	private JTextArea ta = new JTextArea(10,30);
	public JMenuBarTest(String title){
		super(title);
		//���ÿ�ݼ�
		itemFile1.setAccelerator(KeyStroke.getKeyStroke('N',KeyEvent.CTRL_MASK));
		itemFile2.setAccelerator(KeyStroke.getKeyStroke('O',KeyEvent.CTRL_MASK));
		itemFile3.setAccelerator(KeyStroke.getKeyStroke('S',KeyEvent.CTRL_MASK));
		itemFile4.setAccelerator(KeyStroke.getKeyStroke('E',KeyEvent.CTRL_MASK));
		//���JMenuItem��JMenu
		menuFile.add(itemFile1);
		menuFile.add(itemFile2);
		menuFile.add(itemFile3);
		menuFile.addSeparator();//�ӷָ���	
		menuFile.add(itemFile4);
		
		menuHelp.add(itemHelp1);
		menuHelp.addSeparator();//�ӷָ���	
		menuHelp.add(itemHelp2);
		//���JMenu��JBar
		this.setJMenuBar(bar);
		bar.add(menuFile);
		bar.add(menuHelp);
		Container contentPane = this.getContentPane();
		contentPane.add(ta);
		pack();
		this.setVisible(true);	
		//ע�������
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
			ta.setText("�������˲˵��"+e.getActionCommand());			
		}		
	}

	public static void main(String[] args) {
		new JMenuBarTest("���±�");
	}
}
