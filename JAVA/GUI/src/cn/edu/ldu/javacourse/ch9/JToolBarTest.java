package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class JToolBarTest extends JFrame{
	private JToolBar tb = new JToolBar();
	private JButton[] tbButtons;
	public JToolBarTest(){
		super.setTitle("JToolBar����");		
		String[] images = {"1.gif","2.gif"};
		//����ImageIcon����
		ImageIcon[] toolImage = new ImageIcon[images.length];
		tbButtons = new JButton[images.length]; 
		
		for(int i=0;i<images.length;i++){			
			toolImage[i] = new ImageIcon("dir\\"+images[i]);
			tbButtons[i] = new JButton(toolImage[i]);
			tb.add(tbButtons[i]);
		}
		this.add(tb);//��ӹ�������JFrame
		pack();
		setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String[] args) {
		new JToolBarTest();
	}
}

