package cn.edu.ldu.javacourse.ch9;

import java.util.List;
import javax.swing.event.TableModelListener;
import javax.swing.table.TableModel;


public class StudentInfoTableModel implements TableModel {
	private List<StudentInfo> userList; 

	public StudentInfoTableModel(List<StudentInfo> userList) {
		this.userList = userList;
	}

		public int getRowCount() {
		return userList.size();
	}

	
	public int getColumnCount() {
		return 5;
	}

	public Class<?> getColumnClass(int columnIndex) {
		return String.class;
	}

	public Object getValueAt(int rowIndex, int columnIndex) {
		// 第几行，就是列表中的第几个UserInfo对象
		StudentInfo user = userList.get(rowIndex);
		switch(columnIndex)
		{
		case 0:
			return "" + user.getId();
		case 1:
			return user.getName();
		case 2:
			return "" + user.getAge();
		case 3:
			return user.getBirth();
		case 4:
			return user.getAddress();
			
		}
		return "errors";
	}

	// 界面数据有变化时，模型对象的这个方法会被调用，暂时弹出说明框
	public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
		String info = rowIndex + "行" + columnIndex + "列的值改变: "
				+ aValue.toString();
		javax.swing.JOptionPane.showMessageDialog(null, info);
	}

	// 指定某单元格是否可编辑:第一列不可编缉，第一列是ID，是每个对象的唯一识别号
	public boolean isCellEditable(int rowIndex, int columnIndex) {
		if (columnIndex != 0) {
			return true;
		}
		return false;
	}

	// 取每一列的列名
	public String getColumnName(int columnIndex) {
		
			switch(columnIndex)
			{
			case 0:
				return "序 号";
			case 1:
				return "姓 名";
			case 2:
				return "年 龄";
			case 3:
				return "生日";
			case 4:
				return "地址";
				
			}
			return "出错!";
		
	}

	// 添加和移除监听器的方法暂不用，写为空的
	public void addTableModelListener(TableModelListener l) {
	}

	public void removeTableModelListener(TableModelListener l) {
	}
}
