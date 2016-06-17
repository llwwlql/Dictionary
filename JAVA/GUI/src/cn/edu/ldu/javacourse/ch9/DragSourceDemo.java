package cn.edu.ldu.javacourse.ch9;

import java.awt.Cursor;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.Transferable;
import java.awt.dnd.DnDConstants;
import java.awt.dnd.DragGestureEvent;
import java.awt.dnd.DragGestureListener;
import java.awt.dnd.DragSource;

import javax.swing.*;

public class DragSourceDemo {
	JFrame jf = new JFrame("Swing���Ϸ�֧��");
	JLabel srcLabel = new JLabel("AWT���Ϸ�֧��./n" + "�����ı��������������������./n");

	public void init() {
		DragSource dragSource = DragSource.getDefaultDragSource();
		// ��srcLabelת�����Ϸ�Դ�����ܽ��ܸ��ơ��ƶ����ֲ���
		dragSource.createDefaultDragGestureRecognizer(srcLabel,
				DnDConstants.ACTION_COPY_OR_MOVE, new DragGestureListener() {
					public void dragGestureRecognized(DragGestureEvent event) {
						// ��JLabel����ı���Ϣ��װ��Transferable����
						String txt = srcLabel.getText();
						Transferable transferable = new StringSelection(txt);
						// �����ϷŲ���,�ϷŹ�����ʹ����״���
						event.startDrag(
								Cursor.getPredefinedCursor(Cursor.HAND_CURSOR),
								transferable);
					}
				});
		jf.add(new JScrollPane(srcLabel));
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf.pack();
		jf.setVisible(true);
	}

	public static void main(String[] args) {
		new DragSourceDemo().init();
	}
}
