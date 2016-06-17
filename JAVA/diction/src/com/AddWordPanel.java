package com;

import java.awt.Color;
import java.awt.Component;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.text.AbstractDocument.Content;

public class AddWordPanel extends JPanel {
	private JLabel lblNewLabel;
	private JLabel lblNewLabel_1;
	private JPanel addwordpanel;
	private JPanel fpanel;
	public JPanel getFpanel() {
		return fpanel;
	}
	public void setFpanel(JPanel fpanel) {
		this.fpanel = fpanel;
	}
	public JLabel getLblNewLabel() {
		return lblNewLabel;
	}
	public void setLblNewLabel(JLabel lblNewLabel) {
		this.lblNewLabel = lblNewLabel;
	}
	public JLabel getLblNewLabel_1() {
		return lblNewLabel_1;
	}
	public void setLblNewLabel_1(JLabel lblNewLabel_1) {
		this.lblNewLabel_1 = lblNewLabel_1;
	}
	
	/**
	 * Create the panel.
	 */
	public AddWordPanel(int x,int y,int width,int high) {
		super();
		addwordpanel=this;
		setBounds(x, y, width, high);
		setBackground(new java.awt.Color(245, 245, 245));
		setLayout(null);
		lblNewLabel = new JLabel("apple");
		lblNewLabel.setFont(new Font("����", Font.PLAIN, 35));
		lblNewLabel.setBounds(39, 12, 133, 41);
		add(lblNewLabel);
		
		
		//ɾ����ť
		MyButton delButton = new MyButton();
		delButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//���ɾ������
				int i = JOptionPane.showConfirmDialog(null,"   ȷ��Ҫɾ���õ�����","��ʾ",JOptionPane.YES_NO_OPTION);
				if(i==0)
				{
					fpanel.remove(addwordpanel);
					int count=fpanel.getComponentCount();
					int y_panel;
					JPanel com;
					for(int j=0;j<count;j++)
					{
						y_panel= 32+ 148*j;
						com = (JPanel)fpanel.getComponent(j);
						com.setBounds(28, y_panel, 540, 140);
					}
					fpanel.updateUI();
				}
			}
		});
		String path = System.getProperty("user.dir");
		delButton.setIcon(new ImageIcon(path + "//img//del.png"));
		delButton.setBounds(490, 33, 18, 18);
		add(delButton);
		
		
		lblNewLabel_1 = new JLabel("\u82F9\u679C\uFF0C\u82F9\u679C\u6811");
		lblNewLabel_1.setFont(new Font("����", Font.PLAIN, 29));
		lblNewLabel_1.setBounds(39, 63, 458, 52);
		add(lblNewLabel_1);
	}
}