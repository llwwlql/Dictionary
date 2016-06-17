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

        JLabel loginLabel = new JLabel("BBS��ݵ�½");
        JLabel accLabel = new JLabel("�˺ţ�");
        JLabel pswLabel = new JLabel("���룺");
        JTextField loginTf = new JTextField();
        JPasswordField psf = new JPasswordField();
        JRadioButton rb_psw = new JRadioButton("��ס����");
        JRadioButton rb_auto = new JRadioButton("�Զ���½");
        JButton bt1 = new JButton("��¼");
        // Ϊָ���� Container ���� GroupLayout
        GroupLayout layout = new GroupLayout(this.getContentPane());
        this.getContentPane().setLayout(layout);
        //����GroupLayout��ˮƽ�����飬��Խ�ȼ����ParallelGroup�����ȼ�����Խ�ߡ�
        GroupLayout.SequentialGroup hGroup = layout.createSequentialGroup();
        hGroup.addGap(5);//��Ӽ��
        hGroup.addGroup(layout.createParallelGroup().addComponent(accLabel)
                .addComponent(pswLabel));
        hGroup.addGap(5);
        
        hGroup.addGroup(layout.createParallelGroup().addComponent(loginLabel)
                .addComponent(psf).addComponent(rb_psw).addComponent(rb_auto)
                .addComponent(loginTf).addComponent(bt1));
        hGroup.addGap(5);
        
        layout.setHorizontalGroup(hGroup);
        //����GroupLayout�Ĵ�ֱ�����飬��Խ�ȼ����ParallelGroup�����ȼ�����Խ�ߡ�
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
        //���ô�ֱ��
        layout.setVerticalGroup(vGroup);
    }
}
