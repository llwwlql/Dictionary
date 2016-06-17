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
        // 加上窗口监听器，其中主要实现了退出功能
        frame.addWindowListener(new MyWindowListener2());
        label = new JLabel("This is my Window");
        frame.add(label, BorderLayout.NORTH);
        button = new JButton("MyButton");
        frame.add(button, BorderLayout.WEST);

        // 设置按钮事件监听器，按钮按下时会向控制台输出信息
        button.addActionListener(new MyButtonListener2());
 
        textField = new JTextField(40);
        frame.add(textField, BorderLayout.SOUTH);

        // 加上鼠标动作监听器,因为类本身实现了这两个接口，所以参数是this
        frame.addMouseListener(this);
        frame.addMouseMotionListener(this);
        // 可以添加多个监听器
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
    // 因为ActionListener只有一个方法，所以没有适配器
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
