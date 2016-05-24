package reflex;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

public class MethodReflex{
	public void Evaluate() throws Exception{
		Class cls = Person.class;
		Constructor cons = cls.getDeclaredConstructor(new Class[]{String.class,int.class,char.class});
		Object obj = cons.newInstance(new Object[]{"ะกร๗",20,'m'});
		System.out.println(obj);
		Method method = cls.getMethod("print", null);
		method.invoke(obj, null);
	}

}