package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class JComboBoxTest extends JFrame {
	private JComboBox cmb = new JComboBox();
	private JLabel label = new JLabel("要添加项的值：");
	private JTextField tf = new JTextField(5);
	private JButton buttonAdd = new JButton("添加");
	private JButton buttonDel = new JButton("删除");
	private JTextArea ta = new JTextArea(4, 8);
	private JPanel panelNorth = new JPanel();

	public JComboBoxTest(String title) {
		super(title);
		Container contentPane = this.getContentPane();
		panelNorth.add(cmb);
		panelNorth.add(label);
		panelNorth.add(tf);
		panelNorth.add(buttonAdd);
		panelNorth.add(buttonDel);
		contentPane.add(panelNorth, BorderLayout.NORTH);
		contentPane.add(ta, BorderLayout.CENTER);
		buttonAdd.addActionListener(new MyActionListener());
		buttonDel.addActionListener(new MyActionListener());
		cmb.addItemListener(new MyItemListener());
		pack();
		setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	// 监听"添加"和"删除"按钮
	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String command = e.getActionCommand();
			// 添加按钮处理
			if (command.equals("添加")) {
				if (tf.getText().length() != 0) {
					cmb.addItem(tf.getText());// 添加项
					ta.setText("添加成功，添加项：" + tf.getText());
					pack();// 自动调整窗口大小
				} else {
					ta.setText("请输入要添加的项");
				}
			}
			// 删除按钮处理
			if (command.equals("删除")) {
				if (cmb.getSelectedIndex() != -1) {
					// 先获得要删除的项的值
					String strDel = cmb.getSelectedItem().toString();
					cmb.removeItem(strDel);// 删除项
					ta.setText("删除成功，删除项：" + strDel);
					pack();// 自动调整窗口大小
				} else {
					ta.setText("请选择要删除的项");
				}
			}
		}
	}

	private class MyItemListener implements ItemListener {
		public void itemStateChanged(ItemEvent e) {
			String str = e.getItem().toString();
			ta.setText("您选择了项：" + str);
		}
	}

	public static void main(String[] args) {
		new JComboBoxTest("JComboBox测试");
	}
}
