package cn.edu.ldu.javacourse.ch9;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
public class GroupLayoutDemo extends javax.swing.JFrame {
    public static void main(String[] args) {
    	GroupLayoutDemo gf = new GroupLayoutDemo();
    }
   
     public GroupLayoutDemo() {
        this.setVisible(true);
        this.setSize(250, 220);
        this.setVisible(true);
        this.setLocation(400, 200);

        JLabel loginLabel = new JLabel("BBS快捷登陆");
        JLabel accLabel = new JLabel("账号：");
        JLabel pswLabel = new JLabel("密码：");
        JTextField loginTf = new JTextField();
        JPasswordField psf = new JPasswordField();
        JRadioButton rb_psw = new JRadioButton("记住密码");
        JRadioButton rb_auto = new JRadioButton("自动登陆");
        JButton bt1 = new JButton("登录");
        // 为指定的 Container 创建 GroupLayout
        GroupLayout layout = new GroupLayout(this.getContentPane());
        this.getContentPane().setLayout(layout);
        //创建GroupLayout的水平连续组，，越先加入的ParallelGroup，优先级级别越高。
        GroupLayout.SequentialGroup hGroup = layout.createSequentialGroup();
        hGroup.addGap(5);//添加间隔
        hGroup.addGroup(layout.createParallelGroup().addComponent(accLabel)
                .addComponent(pswLabel));
        hGroup.addGap(5);
        
        hGroup.addGroup(layout.createParallelGroup().addComponent(loginLabel)
                .addComponent(psf).addComponent(rb_psw).addComponent(rb_auto)
                .addComponent(loginTf).addComponent(bt1));
        hGroup.addGap(5);
        
        layout.setHorizontalGroup(hGroup);
        //创建GroupLayout的垂直连续组，，越先加入的ParallelGroup，优先级级别越高。
        GroupLayout.SequentialGroup vGroup = layout.createSequentialGroup();
        vGroup.addGap(10);
        vGroup.addGroup(layout.createParallelGroup().addComponent(loginLabel));
        vGroup.addGap(10);
        vGroup.addGroup(layout.createParallelGroup().addComponent(accLabel)
                .addComponent(loginTf));
        vGroup.addGap(5);
        vGroup.addGroup(layout.createParallelGroup().addComponent(pswLabel)
                .addComponent(psf));
        vGroup.addGroup(layout.createParallelGroup().addComponent(rb_psw));

        vGroup.addGroup(layout.createParallelGroup().addComponent(rb_auto));
        vGroup.addGroup(layout.createParallelGroup(Alignment.TRAILING)
                .addComponent(bt1));
        vGroup.addGap(10);
        //设置垂直组
        layout.setVerticalGroup(vGroup);
    }
}
