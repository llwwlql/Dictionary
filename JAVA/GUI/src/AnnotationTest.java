

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class AnnotationTest {
	private JFrame mainWin = new JFrame("ʹ��ע�Ͱ��¼�������");
	//ʹ��ע��Ϊok��ť��cancel��ť���¼�������
	@ActionListenerFor(listener="OkListener")
	private JButton ok = new JButton("ȷ��");
	@ActionListenerFor(listener="CancelListener")
	private JButton cancel = new JButton("ȡ��");
	
	public void init() {
		JPanel jp = new JPanel();
		jp.add(ok);
		jp.add(cancel);
		mainWin.add(jp);

		ActionListenerInstaller.processAnnotations(this);
		
		mainWin.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		mainWin.pack();
		mainWin.setVisible(true);
	}
	
	public static void main(String[] args) {
		new AnnotationTest().init();
	}
}



