package reflex;

import java.lang.reflect.Field;

public class Propertyreflex {
	
	public void Evaluate() throws Exception{
		Class cls = Person.class;
		Field field_name = cls.getDeclaredField("name");
		Field field_age = cls.getDeclaredField("age");
		Field field_sex = cls.getDeclaredField("sex");
		Object obj = cls.newInstance();
		//field_name.setAccessible(true);
		field_name.set(obj, "С��");
		//field_age.setAccessible(true);
		field_age.set(obj, 18);
		field_sex.set(obj, 'm');
		System.out.println(obj);
	}
}