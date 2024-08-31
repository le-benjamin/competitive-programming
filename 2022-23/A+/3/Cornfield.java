import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Cornfield {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int h = in.nextInt(), w = in.nextInt();
            for (int r = 0; r < h; r++) {
                String s = in.next();
                if (s.contains("@")) out.printf("[%d,%d]\n", r, s.indexOf("@"));
            }
        }
    }
}