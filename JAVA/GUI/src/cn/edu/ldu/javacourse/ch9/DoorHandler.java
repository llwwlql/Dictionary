package cn.edu.ldu.javacourse.ch9;

public class DoorHandler implements DoorListener {
    @Override
    public void doorEvent(DoorEvent event) {
        // TODO Auto-generated method stub
        if (event.getDoorState() != null && event.getDoorState().equals("open")) {
            System.out.println("��1��");
        } else {
            System.out.println("��1�ر�");
        }
    }

}
