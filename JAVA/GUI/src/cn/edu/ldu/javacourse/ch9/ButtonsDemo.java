package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import javax.swing.plaf.basic.BasicArrowButton;
import java.awt.event.*;

public class ButtonsDemo extends JFrame{
	private JButton jbutton = new JButton("JButton");
	private BasicArrowButton 
		basicArrowButtonUp= new BasicArrowButton(BasicArrowButton.NORTH),
		basicArrowButtonDown= new BasicArrowButton(BasicArrowButton.SOUTH),
		basicArrowButtonLeft= new BasicArrowButton(BasicArrowButton.WEST),
		basicArrowButtonRight= new BasicArrowButton(BasicArrowButton.EAST);
	private JToggleButton jtoggleButton = new JToggleButton("JToggleButton");
	private JCheckBox jcheckBox = new JCheckBox("JCheckBox");
	private JRadioButton jradioButton = new JRadioButton("JRadioButton");
	public ButtonsDemo(String title){
		super(title);
		Container contentPane = this.getContentPane();
		contentPane.setLayout(new FlowLayout(5));
		contentPane.add(jbutton);
		contentPane.add(basicArrowButtonUp);
		contentPane.add(basicArrowButtonDown);
		contentPane.add(basicArrowButtonLeft);
		contentPane.add(basicArrowButtonRight);
		contentPane.add(jtoggleButton);
		contentPane.add(jcheckBox);
		contentPane.add(jradioButton);
		this.pack();
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String[] args) {
		new ButtonsDemo("java∏˜÷÷∞¥≈•≤‚ ‘");
	}
}
