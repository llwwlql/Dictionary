package cn.edu.ldu.javacourse.ch9;

import java.awt.BorderLayout;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class CustomizedEventButton 
{
    public static void main(String[] args)
    {
       
    }
    public void init()
    {
    	JFrame frame = new JFrame("Event Button");
        JButton UpButton = new JButton("Up!");
        UpButton.addActionListener(new ButtonHandler());
        // 将按钮加入frame
        frame.add(UpButton, BorderLayout.CENTER);
        frame.pack();
        frame.setVisible(true);
    }
}

class ButtonHandler  implements ActionListener
{
    @Override
   public void actionPerformed(ActionEvent e) 
    {
//	    if (DirectionListener == null) return;
//	    DirectionEvent ev;
//	    Object source = this;
//	    if (e.getSource() == UpButton) 
//	    {
//	    	ev = new DirectionEvent(source, DirectionEvent.UP_PRESSED);
//	    	DirectionListener.UpPressed(ev);
//	     }
//    if (e.getSource() == DownButton) 
//    {
//    	ev = new DirectionEvent(source, DirectionEvent.DOWN_PRESSED);
//    	DirectionListener.DownPressed(ev);
//    }
//    if (e.getSource() == LeftButton) 
//    {
//    	ev = new DirectionEvent(source, DirectionEvent.LEFT_PRESSED);
//    	DirectionListener.LeftPressed(ev);
//    }
//    if (e.getSource() == RightButton) 
//    {
//        ev = new DirectionEvent(source, DirectionEvent.RIGHT_PRESSED);
//        DirectionListener.RightPressed(ev);
//     }
 }

}

