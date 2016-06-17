package cn.edu.ldu.javacourse.ch9;

import java.util.EventListener;
public interface DirectionListener extends EventListener 
{
  public abstract void UpPressed(DirectionEvent e);
  public abstract void DownPressed(DirectionEvent e);
  public abstract void LeftPressed(DirectionEvent e);
  public abstract void RightPressed(DirectionEvent e);
}

