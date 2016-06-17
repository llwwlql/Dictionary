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
		{"北京","天津","上海","广州","深圳","南京","重庆","沈阳","西安"};
		list.setListData(citys);
		Container contentPane = this.getContentPane();
		contentPane.setLayout(new FlowLayout(5));//在界面上显示5行
		list.setVisibleRowCount(5);
		contentPane.add(new JScrollPane(list));//使JList带有滚动条
		contentPane.add(ta);
		//注册监听器
		list.addListSelectionListener(new MyListSelectionListener());
		pack();//重新调整
		setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	//处理ListSelection事件
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
		new JListTest("JList测试");
	}
}

