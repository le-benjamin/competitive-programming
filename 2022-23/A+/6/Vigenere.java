import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Vigenere {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            String en = in.next(), key = in.next();
            for (int i = 0; i < en.length(); i++) {
                out.print((char)((en.charAt(i)-'A'-(key.charAt(i%key.length())-'A')+26)%26+'A'));
            }
            out.println();
        }
    }
}