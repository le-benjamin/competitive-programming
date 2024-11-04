import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Ted {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int e = in.nextInt(), l = in.nextInt(), b = in.nextInt(), s = in.nextInt();
            out.println(Math.min(e/2, Math.min(l/4, Math.min(b, s/3))));
        }
    }
}