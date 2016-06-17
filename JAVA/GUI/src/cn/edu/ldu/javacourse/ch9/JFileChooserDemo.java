package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class JFileChooserDemo extends JFrame{
	private JLabel label = new JLabel("所选文件路径：");
	private JTextField tfFileName = new JTextField(25);
	private JButton btnOpen = new JButton("浏览");
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
		//监听btnOpen按钮
		btnOpen.addActionListener(new MyActionListener());
	}
	//Action事件处理
	private class MyActionListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			JFileChooser fc = new JFileChooser("D:\\javaPro");
			int val = fc.showOpenDialog(null);//文件打开对话框
			if(val==fc.APPROVE_OPTION){//正常选择文件
				tfFileName.setText(fc.getSelectedFile().toString());
			}
			else{//未正常选择文件，如选择取消按钮
				tfFileName.setText("未选取文件");
			}			
		}		
	}

	public static void main(String[] args) {
		new JFileChooserDemo("JFileChooser测试");
	}
}
