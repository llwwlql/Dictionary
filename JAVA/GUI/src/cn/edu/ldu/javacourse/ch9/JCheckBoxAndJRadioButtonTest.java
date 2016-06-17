package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class JCheckBoxAndJRadioButtonTest extends JFrame {
	private JPanel panelNorth = new JPanel();
	private JLabel label1 = new JLabel("性别");
	private JRadioButton rb1 = new JRadioButton("男", true);
	private JRadioButton rb2 = new JRadioButton("女");
	private ButtonGroup group = new ButtonGroup();
	private JLabel label2 = new JLabel("擅长");
	private JCheckBox cb1 = new JCheckBox("书法");
	private JCheckBox cb2 = new JCheckBox("唱歌");
	private JCheckBox cb3 = new JCheckBox("跳舞");
	private JButton button = new JButton("确定");
	private JTextArea ta = new JTextArea(6, 10);

	public JCheckBoxAndJRadioButtonTest(String title) {
		super(title);
		Container contentPane = this.getContentPane();
		// 添加JRadioButton到ButtonGroup中
		group.add(rb1);
		group.add(rb2);

		panelNorth.add(label1);
		panelNorth.add(rb1);
		panelNorth.add(rb2);
		panelNorth.add(label2);
		panelNorth.add(cb1);
		panelNorth.add(cb2);
		panelNorth.add(cb3);
		panelNorth.add(button);
		contentPane.add(panelNorth, BorderLayout.NORTH);
		contentPane.add(ta, BorderLayout.CENTER);
		pack();
		// 监听button的Action事件
		button.addActionListener(new MyActionListener());
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String sex = "";// 记录性别
			StringBuffer strBuf = new StringBuffer();// 记录擅长
			// isSelected表示控件被选中
			if (rb1.isSelected()) {
				sex = "男";
			}
			if (rb2.isSelected()) {
				sex = "女";
			}
			if (cb1.isSelected()) {
				strBuf.append("书法 ");
			}
			if (cb2.isSelected()) {
				strBuf.append("唱歌 ");
			}
			if (cb3.isSelected()) {
				strBuf.append("跳舞 ");
			}
			ta.setText("您的性别：" + sex + "\t擅长：" + strBuf.toString() + "\n"
					+ ta.getText());
		}
	}

	public static void main(String[] args) {
		new JCheckBoxAndJRadioButtonTest("单选复选按钮测试");
	}
}
