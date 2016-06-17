package cn.edu.ldu.javacourse.ch9;

public class DoorMain {
    public static void main(String[] args) {
        DoorManager manager = new DoorManager();
        manager.addDoorListener(new DoorHandler());// 给门1增加监听器
        manager.addDoorListener(new DoorHandler2());// 给门2增加监听器
       
        manager.fireWorkspaceOpened();
        System.out.println("warning,有人侵入。。。");
        
        manager.fireWorkspaceClosed();
    }
}
