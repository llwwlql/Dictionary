package com.ldu.edu;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Gui extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private JTextField textField_1;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
//				try {
//					//Gui frame = new Gui();
//					frame.setVisible(true);
//				} catch (Exception e) {
//					e.printStackTrace();
//				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Gui() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 600, 500);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(0, 0, 149, 461);
		contentPane.add(panel);
		panel.setLayout(null);
		
		JButton btnNewButton = new JButton("\u8BCD\u5178");
		btnNewButton.setIcon(null);
		btnNewButton.setFont(new Font("宋体", Font.PLAIN, 14));
		btnNewButton.setBounds(20, 91, 119, 40);
		panel.add(btnNewButton);
		
		JButton button = new JButton("单词本");
		
		button.setFont(new Font("宋体", Font.PLAIN, 14));
		button.setBounds(20, 141, 119, 40);
		panel.add(button);
		
		JButton button_1 = new JButton("\u6BCF\u65E5\u4E00\u6587");
		button_1.setFont(new Font("宋体", Font.PLAIN, 14));
		button_1.setBounds(20, 186, 119, 40);
		panel.add(button_1);
		
		JLabel lblNewLabel = new JLabel("\u67E5\u627E");
		lblNewLabel.setBounds(107, 25, 42, 35);
		panel.add(lblNewLabel);
		lblNewLabel.setFont(new Font("宋体", Font.PLAIN, 18));
		
		JPanel panel_1 = new JPanel();
		panel_1.setBounds(148, 0, 436, 461);
		contentPane.add(panel_1);
		panel_1.setLayout(null);
		panel_1.setVisible(false);
		
		
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				panel_1.setVisible(false);
			}
		});
		
		JPanel panel_2 = new JPanel();
		panel_2.setBounds(10, 23, 416, 40);
		panel_1.add(panel_2);
		panel_2.setLayout(null);
		
		textField = new JTextField();
		textField.setBounds(10, 0, 396, 34);
		panel_2.add(textField);
		textField.setText("\u8BF7\u8F93\u5165\u8981\u67E5\u627E\u7684\u5355\u8BCD");
		textField.setColumns(40);
		
		JPanel panel_3 = new JPanel();
		panel_3.setBounds(10, 72, 416, 379);
		panel_1.add(panel_3);
		panel_3.setLayout(null);
		
		textField_1 = new JTextField();
		textField_1.setBounds(10, 10, 396, 359);
		panel_3.add(textField_1);
		textField_1.setColumns(10);
	}
}
