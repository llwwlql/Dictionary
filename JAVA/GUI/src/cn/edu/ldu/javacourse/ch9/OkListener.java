package cn.edu.ldu.javacourse.ch9;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;

public class OkListener implements ActionListener {
	@Override
	public void actionPerformed(ActionEvent e) {
		JOptionPane.showMessageDialog(null, "单击了确定按钮");
	}
}
