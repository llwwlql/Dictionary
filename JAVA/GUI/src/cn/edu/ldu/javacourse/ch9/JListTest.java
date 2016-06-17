package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
import java.awt.event.*;

public class JListTest extends JFrame{
	private JList list = new JList();
	private JTextArea ta = new JTextArea(6,8);
	public JListTest(String title){
		super(title);
		String[] citys = 
		{"����","���","�Ϻ�","����","����","�Ͼ�","����","����","����"};
		list.setListData(citys);
		Container contentPane = this.getContentPane();
		contentPane.setLayout(new FlowLayout(5));//�ڽ�������ʾ5��
		list.setVisibleRowCount(5);
		contentPane.add(new JScrollPane(list));//ʹJList���й�����
		contentPane.add(ta);
		//ע�������
		list.addListSelectionListener(new MyListSelectionListener());
		pack();//���µ���
		setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	//����ListSelection�¼�
	private class MyListSelectionListener implements ListSelectionListener {
		public void valueChanged(ListSelectionEvent arg0) {
			StringBuffer selectedCitys = new StringBuffer();
			Object[] selectedItems = list.getSelectedValues();
			for(int i=0;i<selectedItems.length;i++){
				selectedCitys.append(selectedItems[i].toString()+"\n");			
			}
			ta.setText(selectedCitys.toString());
			pack();
		}
	}

	public static void main(String[] args) {
		new JListTest("JList����");
	}
}

