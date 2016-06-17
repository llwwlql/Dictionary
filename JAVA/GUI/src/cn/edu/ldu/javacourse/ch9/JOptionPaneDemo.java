package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class JOptionPaneDemo extends JFrame {
	private JButton btn1 = new JButton("消息对话框");
	private JButton btn2 = new JButton("确认对话框");
	private JButton btn3 = new JButton("输入对话框");
	private JButton btn4 = new JButton("选项对话框");

	public JOptionPaneDemo(String title) {
		super(title);
		Container contentPane = this.getContentPane();
		contentPane.setLayout(new FlowLayout(5));
		// 添加按钮
		contentPane.add(btn1);
		contentPane.add(btn2);
		contentPane.add(btn3);
		contentPane.add(btn4);
		pack();
		setVisible(true);
		// 注册监听器
		btn1.addActionListener(new MyActionListener());
		btn2.addActionListener(new MyActionListener());
		btn3.addActionListener(new MyActionListener());
		btn4.addActionListener(new MyActionListener());
	}

	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			int n;
			String str = new String();
			if (e.getActionCommand().equals("消息对话框")) {

				JOptionPane.showMessageDialog(null, "这是一个消息对话框吗？");
			}
			if (e.getActionCommand().equals("确认对话框")) {
				// 显示一个ConfirmDialog，并用变量n接收其返回值
				n = JOptionPane.showConfirmDialog(null, "你确认这是一个确认对话框吗？",
						"对话框title", JOptionPane.YES_NO_OPTION);

				switch (n) {
				case 0:
					JOptionPane.showMessageDialog(null, "您点击了按钮——是");
					break;
				case 1:
					JOptionPane.showMessageDialog(null, "您点击了按钮——否");
					break;
				case -1:
					JOptionPane.showMessageDialog(null, "您点击了退出按钮");
					break;
				}
			}
			if (e.getActionCommand().equals("输入对话框")) {

				str = (String) JOptionPane.showInputDialog(null, "请选择城市：",
						"对话框title", JOptionPane.INFORMATION_MESSAGE, null,
						new String[] { "北京", "上海", "广州" }, "北京");
				// 判断用户选择了ComboBox的哪项
				if (str != null) {
					JOptionPane.showMessageDialog(null, "您选择了" + str);
				}
			}
			if (e.getActionCommand().equals("选项对话框")) {

				n = JOptionPane.showOptionDialog(null, "选项对话框", "对话框title",
						JOptionPane.YES_NO_OPTION,
						JOptionPane.INFORMATION_MESSAGE, null, new String[] {
								"自定义1", "自定义2", "自定义3" }, "自定义1");
				// 判断用户点击了 哪个按钮
				switch (n) {
				case 0:
					JOptionPane.showMessageDialog(null, "您点击了按钮——自定义1");
					break;
				case 1:
					JOptionPane.showMessageDialog(null, "您点击了按钮——自定义2");
					break;
				case 2:
					JOptionPane.showMessageDialog(null, "您点击了按钮——自定义3");
					break;
				case -1:
					JOptionPane.showMessageDialog(null, "您点击了退出按钮");
					break;
				}
			}
		}
	}

	public static void main(String[] args) {
		new JOptionPaneDemo("JOptionPane四种对话框形式测试");
	}
}
