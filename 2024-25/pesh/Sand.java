import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Sand {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            for (int j = 1; j <= x; j++) {
                for (int k = 0; k < j; k++) {
                    out.print("$");
                }
                out.println();
            }
            if (i < n-1) {
                out.println();
            }
        }
    }
}
