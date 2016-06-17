package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class JOptionPaneDemo extends JFrame {
	private JButton btn1 = new JButton("��Ϣ�Ի���");
	private JButton btn2 = new JButton("ȷ�϶Ի���");
	private JButton btn3 = new JButton("����Ի���");
	private JButton btn4 = new JButton("ѡ��Ի���");

	public JOptionPaneDemo(String title) {
		super(title);
		Container contentPane = this.getContentPane();
		contentPane.setLayout(new FlowLayout(5));
		// ��Ӱ�ť
		contentPane.add(btn1);
		contentPane.add(btn2);
		contentPane.add(btn3);
		contentPane.add(btn4);
		pack();
		setVisible(true);
		// ע�������
		btn1.addActionListener(new MyActionListener());
		btn2.addActionListener(new MyActionListener());
		btn3.addActionListener(new MyActionListener());
		btn4.addActionListener(new MyActionListener());
	}

	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			int n;
			String str = new String();
			if (e.getActionCommand().equals("��Ϣ�Ի���")) {

				JOptionPane.showMessageDialog(null, "����һ����Ϣ�Ի�����");
			}
			if (e.getActionCommand().equals("ȷ�϶Ի���")) {
				// ��ʾһ��ConfirmDialog�����ñ���n�����䷵��ֵ
				n = JOptionPane.showConfirmDialog(null, "��ȷ������һ��ȷ�϶Ի�����",
						"�Ի���title", JOptionPane.YES_NO_OPTION);

				switch (n) {
				case 0:
					JOptionPane.showMessageDialog(null, "������˰�ť������");
					break;
				case 1:
					JOptionPane.showMessageDialog(null, "������˰�ť������");
					break;
				case -1:
					JOptionPane.showMessageDialog(null, "��������˳���ť");
					break;
				}
			}
			if (e.getActionCommand().equals("����Ի���")) {

				str = (String) JOptionPane.showInputDialog(null, "��ѡ����У�",
						"�Ի���title", JOptionPane.INFORMATION_MESSAGE, null,
						new String[] { "����", "�Ϻ�", "����" }, "����");
				// �ж��û�ѡ����ComboBox������
				if (str != null) {
					JOptionPane.showMessageDialog(null, "��ѡ����" + str);
				}
			}
			if (e.getActionCommand().equals("ѡ��Ի���")) {

				n = JOptionPane.showOptionDialog(null, "ѡ��Ի���", "�Ի���title",
						JOptionPane.YES_NO_OPTION,
						JOptionPane.INFORMATION_MESSAGE, null, new String[] {
								"�Զ���1", "�Զ���2", "�Զ���3" }, "�Զ���1");
				// �ж��û������ �ĸ���ť
				switch (n) {
				case 0:
					JOptionPane.showMessageDialog(null, "������˰�ť�����Զ���1");
					break;
				case 1:
					JOptionPane.showMessageDialog(null, "������˰�ť�����Զ���2");
					break;
				case 2:
					JOptionPane.showMessageDialog(null, "������˰�ť�����Զ���3");
					break;
				case -1:
					JOptionPane.showMessageDialog(null, "��������˳���ť");
					break;
				}
			}
		}
	}

	public static void main(String[] args) {
		new JOptionPaneDemo("JOptionPane���ֶԻ�����ʽ����");
	}
}
