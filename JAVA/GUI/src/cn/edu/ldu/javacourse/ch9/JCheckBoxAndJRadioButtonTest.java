package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class JCheckBoxAndJRadioButtonTest extends JFrame {
	private JPanel panelNorth = new JPanel();
	private JLabel label1 = new JLabel("�Ա�");
	private JRadioButton rb1 = new JRadioButton("��", true);
	private JRadioButton rb2 = new JRadioButton("Ů");
	private ButtonGroup group = new ButtonGroup();
	private JLabel label2 = new JLabel("�ó�");
	private JCheckBox cb1 = new JCheckBox("�鷨");
	private JCheckBox cb2 = new JCheckBox("����");
	private JCheckBox cb3 = new JCheckBox("����");
	private JButton button = new JButton("ȷ��");
	private JTextArea ta = new JTextArea(6, 10);

	public JCheckBoxAndJRadioButtonTest(String title) {
		super(title);
		Container contentPane = this.getContentPane();
		// ���JRadioButton��ButtonGroup��
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
		// ����button��Action�¼�
		button.addActionListener(new MyActionListener());
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String sex = "";// ��¼�Ա�
			StringBuffer strBuf = new StringBuffer();// ��¼�ó�
			// isSelected��ʾ�ؼ���ѡ��
			if (rb1.isSelected()) {
				sex = "��";
			}
			if (rb2.isSelected()) {
				sex = "Ů";
			}
			if (cb1.isSelected()) {
				strBuf.append("�鷨 ");
			}
			if (cb2.isSelected()) {
				strBuf.append("���� ");
			}
			if (cb3.isSelected()) {
				strBuf.append("���� ");
			}
			ta.setText("�����Ա�" + sex + "\t�ó���" + strBuf.toString() + "\n"
					+ ta.getText());
		}
	}

	public static void main(String[] args) {
		new JCheckBoxAndJRadioButtonTest("��ѡ��ѡ��ť����");
	}
}
