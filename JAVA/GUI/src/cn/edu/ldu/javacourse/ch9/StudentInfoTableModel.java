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
		// �ڼ��У������б��еĵڼ���UserInfo����
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

	// ���������б仯ʱ��ģ�Ͷ������������ᱻ���ã���ʱ����˵����
	public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
		String info = rowIndex + "��" + columnIndex + "�е�ֵ�ı�: "
				+ aValue.toString();
		javax.swing.JOptionPane.showMessageDialog(null, info);
	}

	// ָ��ĳ��Ԫ���Ƿ�ɱ༭:��һ�в��ɱ༩����һ����ID����ÿ�������Ψһʶ���
	public boolean isCellEditable(int rowIndex, int columnIndex) {
		if (columnIndex != 0) {
			return true;
		}
		return false;
	}

	// ȡÿһ�е�����
	public String getColumnName(int columnIndex) {
		
			switch(columnIndex)
			{
			case 0:
				return "�� ��";
			case 1:
				return "�� ��";
			case 2:
				return "�� ��";
			case 3:
				return "����";
			case 4:
				return "��ַ";
				
			}
			return "����!";
		
	}

	// ��Ӻ��Ƴ��������ķ����ݲ��ã�дΪ�յ�
	public void addTableModelListener(TableModelListener l) {
	}

	public void removeTableModelListener(TableModelListener l) {
	}
}
