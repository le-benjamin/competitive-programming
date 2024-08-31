import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Archibald {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int n = in.nextInt();
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    out.print("@");
                }
                out.println();
            }
            out.println();
        }
    }
}