package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class JComboBoxTest extends JFrame {
	private JComboBox cmb = new JComboBox();
	private JLabel label = new JLabel("Ҫ������ֵ��");
	private JTextField tf = new JTextField(5);
	private JButton buttonAdd = new JButton("���");
	private JButton buttonDel = new JButton("ɾ��");
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

	// ����"���"��"ɾ��"��ť
	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String command = e.getActionCommand();
			// ��Ӱ�ť����
			if (command.equals("���")) {
				if (tf.getText().length() != 0) {
					cmb.addItem(tf.getText());// �����
					ta.setText("��ӳɹ�������" + tf.getText());
					pack();// �Զ��������ڴ�С
				} else {
					ta.setText("������Ҫ��ӵ���");
				}
			}
			// ɾ����ť����
			if (command.equals("ɾ��")) {
				if (cmb.getSelectedIndex() != -1) {
					// �Ȼ��Ҫɾ�������ֵ
					String strDel = cmb.getSelectedItem().toString();
					cmb.removeItem(strDel);// ɾ����
					ta.setText("ɾ���ɹ���ɾ���" + strDel);
					pack();// �Զ��������ڴ�С
				} else {
					ta.setText("��ѡ��Ҫɾ������");
				}
			}
		}
	}

	private class MyItemListener implements ItemListener {
		public void itemStateChanged(ItemEvent e) {
			String str = e.getItem().toString();
			ta.setText("��ѡ�����" + str);
		}
	}

	public static void main(String[] args) {
		new JComboBoxTest("JComboBox����");
	}
}
