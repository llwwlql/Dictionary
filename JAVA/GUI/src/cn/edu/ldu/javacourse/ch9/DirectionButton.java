package cn.edu.ldu.javacourse.ch9;

import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;

import javax.swing.JButton;

public class DirectionButton extends JButton {
    private Collection listeners;
    private int direction;
    public DirectionButton(String name,int dir)
    {
    	super(name);
    	this.direction = dir;
    }
    public void addDirectionListener(DirectionListener listener) {
        if (listeners == null) {
            listeners = new HashSet();
        }
        listeners.add(listener);
    }

    public void removeDirectionListener(DirectionListener listener) {
        if (listeners == null)
            return;
        listeners.remove(listener);
    }

    protected void fireWorkspaceOpened() {
        if (listeners == null)
            return;
        DirectionEvent event = new DirectionEvent(this, direction);
        notifyListeners(event);
    }

    /**
     * 通知所有的Listener
     */
    private void notifyListeners(DirectionEvent event) {
        Iterator iter = listeners.iterator();
        while (iter.hasNext()) {
        	DirectionListener listener = (DirectionListener) iter.next();
            listener.DownPressed(event);
        }
    }
}
