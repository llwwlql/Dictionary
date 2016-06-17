package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;

public class BoxLayoutTest {
	public static void main(String[] args) {

		JFrame frame = new JFrame("BoxLayout Test");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container panel = frame.getContentPane();
		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
		for (float align = 0.0f; align <= 1.0f; align += 0.25f) {
			JButton button = new JButton("X align = " + align);
			button.setAlignmentX(align);
			panel.add(button);
		}
		frame.setSize(400, 300);
		frame.setVisible(true);
	}
}
