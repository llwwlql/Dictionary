package com;
import java.awt.*;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseEvent;
import java.awt.image.ImageObserver;
import java.awt.image.ImageProducer;
import java.net.URL;
import java.awt.event.MouseAdapter;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.InputMethodListener;
import java.awt.event.InputMethodEvent;

public class DicGUI extends JFrame {

	private JPanel contentPane;
	private JTextField textField;	//����
	private JTextArea showChinese;		//��ʾ������˼
	private JLabel showEnglish;	//��ʾӢ�ĵ���
	private JLabel pclabel;
	private JLabel downlabel;
	private String path;
	private String searchWord = new String();
	private JPanel droppanel;	//ģ����ѯ����������
	public JLabel getShowEnglish() {
		return showEnglish;
	}

	public void setShowEnglish(JLabel showEnglish) {
		this.showEnglish = showEnglish;
	}
	public JTextArea getTextArea() {
		return showChinese;
	}

	public void setTextArea(JTextArea textArea) {
		this.showChinese = textArea;
	}

	public JTextField getTextField() {
		return textField;
	}

	public void setTextField(JTextField textField) {
		this.textField = textField;
	}

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					DicGUI frame = new DicGUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public DicGUI() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 800, 600);
		setLocationRelativeTo(null);	//������ʾ
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		contentPane.setLayout(null);
		path=System.getProperty("user.dir"); 
		this.make_panel();
		this.make_panel_1();
		this.make_panel_2();
		this.make_panel_3();
	}
	
	public void make_panel()
	{//��ť��
		JPanel panel = new JPanel();
		panel.setBackground(Color.WHITE);
		panel.setBounds(0, 0, 160, 561);
		contentPane.add(panel);
		//button_1
		MyButton button_1 = new MyButton();
		button_1.setBounds(10, 138, 139, 47);
		button_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Component[] com = new JPanel[4];
				for(int i=0;i<=3;i++)
					com[i] = contentPane.getComponent(i);
				com[1].setVisible(true);
				com[2].setVisible(false);
				com[3].setVisible(false);
			}
		});
		panel.setLayout(null);
		button_1.setIcon(new ImageIcon(path + "//img//Button_1.png"));
		button_1.setContentAreaFilled(false);
		button_1.setBorderPainted(false);
		panel.add(button_1);
		
		
		
		
		//button_2
		JButton button_2 = new MyButton();
		button_2.setBounds(10, 208, 139, 47);
		button_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Component[] com = new JPanel[4];
				for(int i=0;i<=3;i++)
					com[i] = contentPane.getComponent(i);
				com[1].setVisible(false);
				com[2].setVisible(true);
				com[3].setVisible(false);
			}
		});
		button_2.setIcon(new ImageIcon(path+"\\img\\Button_2.png"));
		button_2.setBorderPainted(false);
		button_2.setContentAreaFilled(false);
		panel.add(button_2);
		
		
		
		
		//button_3
		JButton button_3 = new MyButton();
		button_3.setBounds(10, 277, 139, 47);
		button_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Component[] com = new JPanel[4];
				for(int i=0;i<=3;i++)
					com[i] = contentPane.getComponent(i);
				com[1].setVisible(false);
				com[2].setVisible(false);
				com[3].setVisible(true);
			}
		});
		button_3.setIcon(new ImageIcon(path+"\\img\\Button_3.png"));
		button_3.setBorderPainted(false);
		button_3.setContentAreaFilled(false);
		panel.add(button_3);
		
		JLabel bclable = new JLabel("");
		bclable.setBounds(0, 0, 160, 561);
		bclable.setIcon(new ImageIcon(path+"\\img\\panel_1.jpg"));
		panel.add(bclable);
	}
	
	public void make_panel_1()
	{//�ʵ�ҳ
		JPanel panel_1 = new JPanel();
		panel_1.setBackground(Color.WHITE);
		panel_1.setBounds(157, 0, 627, 561);
		contentPane.add(panel_1);
		textField = new JTextField();
		textField.setBackground(new java.awt.Color(232, 232, 232));
		textField.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(232, 232, 232)));
		textField.getDocument().addDocumentListener(new DocumentListener() {
			@Override
			public void removeUpdate(DocumentEvent e) {
				// TODO �Զ����ɵķ������					
				searchWord = textField.getText();
				DropText dropword;
				for(int i=0;i<=4;i++)
				{
					dropword = (DropText)droppanel.getComponent(i);
					//�������ݿ�ģ������
				}
				droppanel.updateUI();
			}
			
			@Override
			public void insertUpdate(DocumentEvent e) {
				// TODO �Զ����ɵķ������
				searchWord = textField.getText();
				DropText dropword;
				for(int i=0;i<=4;i++)
				{
					dropword = (DropText)droppanel.getComponent(i);
					//�������ݿ�ģ������
				}
				droppanel.updateUI();
			}
			
			@Override
			public void changedUpdate(DocumentEvent e) {
				// TODO �Զ����ɵķ������
				searchWord = textField.getText();					
				DropText dropword;
				for(int i=0;i<=4;i++)
				{
					dropword = (DropText)droppanel.getComponent(i);
					//�������ݿ�ģ������
				}
				droppanel.updateUI();
			}
		});

		textField.setBounds(96, 27, 439, 40);
		textField.addKeyListener(new KeyAdapter() {
			@Override
			//���̲�������ʱ�Ĵ���
			public void keyTyped(KeyEvent e) {
				pclabel.setVisible(false);
				downlabel.setVisible(true);
				droppanel.setVisible(true);
				if(e.getKeyChar() == KeyEvent.VK_ENTER)
				{
					droppanel.setVisible(false);
					String searchword = new String(textField.getText());
					//���ݿ����
				}
				if(searchWord.length()==0)
					droppanel.setVisible(false);
				contentPane.updateUI();
			}
		});
		panel_1.setLayout(null);
		textField.setFont(new Font("����", Font.PLAIN, 18));
		panel_1.add(textField);
		textField.setColumns(10);
		
		MyButton addButton = new MyButton();
		addButton.setIcon(new ImageIcon(path+"\\img\\add.png"));
		addButton.setBounds(530, 130, 19, 20);
		addButton.setToolTipText("�������ʱ�");
		addButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int i = JOptionPane.showConfirmDialog(null,"   ȷ��Ҫ���ӵ����ʱ���","��ʾ",JOptionPane.YES_NO_OPTION);
				if(i==0)
				{
					Component com = contentPane.getComponent(2);
					addWord((JPanel_2)com);
				}
			}
		});
		
		MyButton searchButton = new MyButton();
		searchButton.setBounds(533, 27, 72, 40);
		searchButton.addActionListener(new ActionListener() {
			//�������
			public void actionPerformed(ActionEvent e) {
				//��ȡtextField��ֵ����д�뵽textField_1
				showChinese.setVisible(true);
				showEnglish.setVisible(true);
				droppanel.setVisible(false);
				if(true)
				{//���ҳɹ�
					panel_1.add(addButton);
				}
				else
				{//����ʧ��
					
				}
				panel_1.updateUI();
			}
		});
		searchButton.setIcon(new ImageIcon(path + "\\img\\search.png"));
		addButton.setBorderPainted(false);
		panel_1.add(searchButton);
		
		JLabel lblNewLabel = new JLabel("");
		lblNewLabel.setBounds(24, 27, 72, 40);
		lblNewLabel.setIcon(new ImageIcon(path + "\\img\\search-pre.png"));
		panel_1.add(lblNewLabel);
		
		showChinese = new JTextArea();
		showChinese.setBounds(24, 191, 581, 99);
		panel_1.add(showChinese);
		showChinese.setVisible(false);
		showChinese.setEditable(false);	//���ɱ༭
		
		showEnglish = new JLabel("appleaaaaaaaaa");
		showEnglish.setBounds(24, 115, 500, 40);
		showEnglish.setFont(new Font("����", Font.PLAIN, 42));
		showEnglish.setVisible(false);
		panel_1.add(showEnglish);
		
		pclabel = new JLabel("");
		pclabel.setBounds(80, 77, 474, 474);
		pclabel.setIcon(new ImageIcon(path+"\\img\\pic.jpg"));
		panel_1.add(pclabel);
		
		droppanel = new JPanel();
		droppanel.setBounds(96, 65, 439, 200);
		droppanel.setLayout(null);
		DropText[] dropword = new DropText[5];
		
		for(int i=0;i<=4;i++)
		{
			dropword[i] = new DropText(droppanel);
			int y=i*40;
			dropword[i].setBounds(0,y,439,40);
			droppanel.add(dropword[i]);
			//dropword[i].setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(51, 255, 51)));
		}
		panel_1.add(droppanel);
		
		downlabel = new JLabel("");
		downlabel.setIcon(new ImageIcon(path +"\\img\\down_1.png"));
		downlabel.setBounds(0, 514, 627, 47);
		downlabel.setVisible(false);
		panel_1.add(downlabel);
		droppanel.setVisible(false);
	}
	
	public void make_panel_2()
	{//���ʱ�ҳ
		JPanel_2 panel_2 = new JPanel_2(contentPane);
		contentPane.add(panel_2);
		JPanel panel = new JPanel();
		panel.setLayout(null);
		panel.setBounds(10, 77, 607, 474);
		panel.setBackground(Color.WHITE);
		panel_2.setPanel(panel);
		
		JScrollPane scrollPane = new JScrollPane(panel);
		scrollPane.setBounds(10, 77, 607, 474);
		scrollPane.setBackground(Color.WHITE);
		panel.setPreferredSize(new Dimension(scrollPane.getWidth() - 50, scrollPane.getHeight()*4));
		JLabel bcLabel =(JLabel)panel_2.getComponent(0);
		bcLabel.add(scrollPane);
		panel_2.updateUI();
		panel_2.setVisible(false);
		panel.revalidate(); //������������,�ҵĿ��߱���
	}
	
	public void make_panel_3()
	{//ÿ��һ��		
		JPanel_3 panel_3 = new JPanel_3();
		contentPane.add(panel_3);
		panel_3.setVisible(false);
		
	}
	
	public void addWord(JPanel_2 panel_2){
		//ͳ�����������	
		JPanel jp = panel_2.getPanel();
		int count = jp.getComponentCount();
		int y_panel = 32+ 148*count;
		AddWordPanel addwordpanel = new AddWordPanel(20, y_panel, 545, 140);
		//�ı䵥�����ԣ��������ݿ�
		addwordpanel.setFpanel(panel_2.getPanel());
		jp.add(addwordpanel);
	}
}