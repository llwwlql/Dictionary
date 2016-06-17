import javax.swing.*;

import java.awt.*;
public class JFrameTest extends JFrame{
	private JButton button1 = new JButton("button1");
	private JButton button2 = new JButton("button2");
	private JButton	button3 = new JButton("button3");
	public JFrameTest(String title){
		super(title);
		this.setBounds(300, 150, 500, 300);
		//setBounds(窗口所在横坐标，窗口所在纵坐标，窗口宽，窗口高);
		Container contentPane = this.getContentPane();
		//获取内容面板
		contentPane.setLayout(new FlowLayout(10));
		contentPane.add(button1);
		contentPane.add(button2);
		//添加按钮
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args)
	{
		new JFrameTest("JFrame测试");
	}
}
