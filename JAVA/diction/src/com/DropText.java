package com;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class DropText extends JTextField{
	private JPanel fpanel;
	public DropText(JPanel fpanel){
		super();
		this.fpanel = fpanel;
		setBorder(null);
		setEditable(false);
		setText("");
		this.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				fpanel.setVisible(false);
				String search = new String(getText());
			}
			@Override
			public void mouseEntered(MouseEvent e) {
				
			}
			@Override
			public void mouseExited(MouseEvent e) {
				
			}
		});
	}
}
