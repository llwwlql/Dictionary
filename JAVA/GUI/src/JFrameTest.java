import javax.swing.*;

import java.awt.*;
public class JFrameTest extends JFrame{
	private JButton button1 = new JButton("button1");
	private JButton button2 = new JButton("button2");
	private JButton	button3 = new JButton("button3");
	public JFrameTest(String title){
		super(title);
		this.setBounds(300, 150, 500, 300);
		//setBounds(�������ں����꣬�������������꣬���ڿ����ڸ�);
		Container contentPane = this.getContentPane();
		//��ȡ�������
		contentPane.setLayout(new FlowLayout(10));
		contentPane.add(button1);
		contentPane.add(button2);
		//��Ӱ�ť
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args)
	{
		new JFrameTest("JFrame����");
	}
}
