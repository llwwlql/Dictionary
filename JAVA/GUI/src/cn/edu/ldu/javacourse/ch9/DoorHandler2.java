package cn.edu.ldu.javacourse.ch9;

public class DoorHandler2 implements DoorListener {

    @Override
    public void doorEvent(DoorEvent event) {
        // TODO Auto-generated method stub
        if (event.getDoorState() != null && event.getDoorState().equals("open")) {
            System.out.println("��2�򿪣�ͬʱ�����ȵĵ�");
        } else {
            System.out.println("��2�رգ�ͬʱ�ر����ȵĵ�");
        }
    }

}
