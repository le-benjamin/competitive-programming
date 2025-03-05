import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Dog {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            // top
            for (int j = 0; j < x; j++) {
                out.print("@");
            }
            out.println();

            if (x == 1) continue;

            // mid section
            for (int j = 0; j < x-2; j++) {
                out.print("@");
                for (int k = 0; k < x-2; k++) {
                    out.print(" ");
                }
                out.println("@");
            }

            // bot
            for (int j = 0; j < x; j++) {
                out.print("@");
            }
            out.println();
        }
    }
}
