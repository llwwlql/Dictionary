package cn.edu.ldu.javacourse.ch9;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;

public class CancelListener implements ActionListener {
	@Override
	public void actionPerformed(ActionEvent e) {
		JOptionPane.showMessageDialog(null, "������ȡ����ť");
	}
}