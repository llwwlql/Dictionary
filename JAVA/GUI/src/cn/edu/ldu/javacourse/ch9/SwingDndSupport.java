package cn.edu.ldu.javacourse.ch9;

import java.awt.BorderLayout;

import javax.swing.*;

public class SwingDndSupport  
{  
    JFrame jf = new JFrame("Swing���Ϸ�֧��");  
    JTextArea srcTxt = new JTextArea(8 , 30);  
    JTextField jtf = new JTextField(34);  
    public void init()  
    {  
        srcTxt.append("AWT���Ϸ�֧��./n");  
        srcTxt.append("�����ı��������������������./n");  
        //�����ı���͵����ı�����Ϸ�֧��  
        srcTxt.setDragEnabled(true);  
        jtf.setDragEnabled(true);  
        jf.add(new JScrollPane(srcTxt));  
        jf.add(jtf , BorderLayout.SOUTH);  
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        jf.pack();  
        jf.setVisible(true);  
    }  
    public static void main(String[] args)   
    {  
        new SwingDndSupport().init();  
    }  
} 
