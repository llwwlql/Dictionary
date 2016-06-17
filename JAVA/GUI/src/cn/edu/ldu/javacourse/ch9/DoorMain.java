package cn.edu.ldu.javacourse.ch9;

public class DoorMain {
    public static void main(String[] args) {
        DoorManager manager = new DoorManager();
        manager.addDoorListener(new DoorHandler());// ����1���Ӽ�����
        manager.addDoorListener(new DoorHandler2());// ����2���Ӽ�����
       
        manager.fireWorkspaceOpened();
        System.out.println("warning,�������롣����");
        
        manager.fireWorkspaceClosed();
    }
}
