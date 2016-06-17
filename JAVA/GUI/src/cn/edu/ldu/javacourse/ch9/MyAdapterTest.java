package cn.edu.ldu.javacourse.ch9;

import java.awt.*;
import java.awt.TextField;
import java.awt.event.*;
import java.sql.Date;
import javax.swing.*;

public class MyAdapterTest extends MouseAdapter
{
    private JFrame frame;
    private JLabel label;
    private JButton button;
    private JTextField textField;

    public void go()
    {

        frame = new JFrame("Mouse Adapter");
        // ���ϴ��ڼ�������������Ҫʵ�����˳�����
        frame.addWindowListener(new MyWindowListener2());
        label = new JLabel("This is my Window");
        frame.add(label, BorderLayout.NORTH);
        button = new JButton("MyButton");
        frame.add(button, BorderLayout.WEST);

        // ���ð�ť�¼�����������ť����ʱ�������̨�����Ϣ
        button.addActionListener(new MyButtonListener2());
 
        textField = new JTextField(40);
        frame.add(textField, BorderLayout.SOUTH);

        // ������궯��������,��Ϊ�౾��ʵ�����������ӿڣ����Բ�����this
        frame.addMouseListener(this);
        frame.addMouseMotionListener(this);
        // ������Ӷ��������
        frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args)
    {
    	MyAdapterTest window = new MyAdapterTest();
        window.go();
    }

    @Override
    public void mouseMoved(MouseEvent e)
    {
        String str = "x = " + e.getX() + ", y = " + e.getY();
        this.textField.setText(str);
        System.out.println(str);
    }

    @Override
    public void mouseExited(MouseEvent e)
    {
        this.textField.setText("the mouse has exited.");
    }
}

class MyButtonListener2 implements ActionListener
{
    // ��ΪActionListenerֻ��һ������������û��������
    @SuppressWarnings("deprecation")
    @Override
    public void actionPerformed(ActionEvent e)
    {
        System.out.println("The Button is pressed!");
        Long time = e.getWhen();
        System.out.println("timestamp: " + time);
         Date date = new Date(time);
        System.out.println(date.toLocaleString());
    }
}

class MyWindowListener2 extends WindowAdapter
{
    @Override
    public void windowClosing(WindowEvent e)
    {
        System.out.println("windowClosing");
        System.exit(0);
    }
}
