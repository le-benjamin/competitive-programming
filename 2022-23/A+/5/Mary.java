import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Mary {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int n = in.nextInt();
            int ret = 1;
            boolean hasZero = false;
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                if (x == 0) hasZero = true;
                if (x > 0) ret *= x;
            }
            if (n == 0) out.println(0);
            else out.println(out);
        }
    }
}