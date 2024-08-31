import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Order {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            String s = in.next();
            int cnt = 0;
            for (int i = 0; i < s.length(); i++) {
                for (int j = i; j < s.length(); j++) {
                    if (s.charAt(i) == s.charAt(j)) cnt++;
                }
            }
            out.println(cnt);
        }
    }
}