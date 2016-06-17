package cn.edu.ldu.javacourse.ch9;

import java.util.ArrayList;
import java.util.List;


public class JTableUI {
	
	public static void main(String[] args) {
		JTableUI lu = new JTableUI();
		lu.setupUI();
	}

	
	public void setupUI() {
		javax.swing.JFrame jf = new javax.swing.JFrame("JTable-TableModel示例");
		jf.setSize(400, 400);
		java.awt.FlowLayout fl = new java.awt.FlowLayout();
		jf.setLayout(fl);
		
		final javax.swing.JTable table = new javax.swing.JTable();
		
		List<StudentInfo> userList = getUserList();
		// 创建我们实现的TableModel对象,创建时要传入用户列表对象
		StudentInfoTableModel tm = new StudentInfoTableModel(userList);
		table.setModel(tm);
		
		jf.add(table);
		jf.setDefaultCloseOperation(3);
		jf.setVisible(true);
	}

	// 模拟生成用户对象列表
	private List<StudentInfo> getUserList() {
		List<StudentInfo> uList = new ArrayList<StudentInfo>();
		for (int i = 0; i < 100; i++) {
			StudentInfo user = new StudentInfo();
			user.setId(i + 1);
			user.setAge(20 + i);
			user.setName("用户" + i);
			user.setAddress("www.ldu.edu.cn");
			user.setBirth("2014-1-1");
			uList.add(user);
		}
		return uList;
	}
}
