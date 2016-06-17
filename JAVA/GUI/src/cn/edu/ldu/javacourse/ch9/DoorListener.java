package cn.edu.ldu.javacourse.ch9;

import java.util.EventListener;

public interface DoorListener extends EventListener {
    public void doorEvent(DoorEvent event);
}