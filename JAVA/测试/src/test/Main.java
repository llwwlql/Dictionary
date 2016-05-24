package test;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static int sum = 0;

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int n = sc.nextInt();
        sc.nextLine();
        while (n > 0) {
            String pw = sc.nextLine();

            pewer(str, ha(pw));
            n--;
        }
        System.out.println(sum);
    }

    private static void pewer(String str, String pw) {
        // TODO Auto-generated method stub
        for (int i = 0; i + 8 <= str.length(); i++) {
            String new_str = str.substring(i, i + 8);
            
            if (ha(new_str).equals(pw)) {
            	System.out.println(new_str);
                sum++;
            }
        }
        System.out.println("***"+pw);
    }

    private static String ha(String st) {
        char[] ss = st.toCharArray();
        Arrays.sort(ss);
        String rts = new String(ss);
        return rts;
    }

}