import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Vova {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        for (int i = 1; i <= tc; i++) {
            out.printf("Case #%d: ", i);
            long x1 = in.nextLong();
            long y1 = in.nextLong();
            long x2 = in.nextLong();
            long y2 = in.nextLong();
            long l = in.nextLong();
            long mn = Math.abs(x2-x1) + Math.abs(y2-y1);
            if (l < mn) {
                out.println("NO");
            }
            else if (l%2 != mn%2) {
                out.println("NO");
            }
            else {
                out.println("YES");
            }
        }
    }
}