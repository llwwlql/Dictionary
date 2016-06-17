

import java.awt.event.ActionListener;
import java.lang.reflect.Field;

import javax.swing.AbstractButton;
public class ActionListenerInstaller {
	public static void processAnnotations(Object obj) {
		try {
			Class clazz = obj.getClass();
			for (Field fd : clazz.getDeclaredFields()) {
				//将指定Field设置成可自由访问的，避免private的Field不可访问
				fd.setAccessible(true);
				//获取指定的Field的ActionListenerFor类型的注释
				ActionListenerFor  actionFor = fd.getAnnotation(ActionListenerFor.class);
				if (actionFor != null && fd.get(obj) instanceof AbstractButton) {
					//获取a注释里的元数据（它是一个监听器类）
					Class listenerClazz = Class.forName("cn.edu.ldu.javacourse.ch9."+actionFor.listener());
					//使用反射来创建listener类的对象
ActionListener  aListener = (ActionListener)listenerClazz.newInstance();
					//获取指定对象中fd实际对应的对象
					AbstractButton abutton = (AbstractButton)fd.get(obj);
					//为获取到的对象添加事件监听器
					abutton.addActionListener(aListener);
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
