package cn.edu.ldu.javacourse.ch9;

import java.util.EventObject;

public class DoorEvent extends EventObject {

    private static final long serialVersionUID = 6496098798146410884L;

    private String doorState = "";// ��ʾ�ŵ�״̬���С������͡��ء�����

    public DoorEvent(Object source, String doorState) {
        super(source);
        this.doorState = doorState;
    }

    public void setDoorState(String doorState) {
        this.doorState = doorState;
    }

    public String getDoorState() {
        return this.doorState;
    }

}
