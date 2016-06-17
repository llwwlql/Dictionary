

import java.awt.event.ActionListener;
import java.lang.reflect.Field;

import javax.swing.AbstractButton;
public class ActionListenerInstaller {
	public static void processAnnotations(Object obj) {
		try {
			Class clazz = obj.getClass();
			for (Field fd : clazz.getDeclaredFields()) {
				//��ָ��Field���óɿ����ɷ��ʵģ�����private��Field���ɷ���
				fd.setAccessible(true);
				//��ȡָ����Field��ActionListenerFor���͵�ע��
				ActionListenerFor  actionFor = fd.getAnnotation(ActionListenerFor.class);
				if (actionFor != null && fd.get(obj) instanceof AbstractButton) {
					//��ȡaע�����Ԫ���ݣ�����һ���������ࣩ
					Class listenerClazz = Class.forName("cn.edu.ldu.javacourse.ch9."+actionFor.listener());
					//ʹ�÷���������listener��Ķ���
ActionListener  aListener = (ActionListener)listenerClazz.newInstance();
					//��ȡָ��������fdʵ�ʶ�Ӧ�Ķ���
					AbstractButton abutton = (AbstractButton)fd.get(obj);
					//Ϊ��ȡ���Ķ�������¼�������
					abutton.addActionListener(aListener);
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
