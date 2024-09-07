import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Spin {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int x = in.nextInt();
            String[] g = new String[x];
            for (int i = 0; i < x; i++) {
                g[i] = in.next();
            }

            String[] tspin = 
                {"#.."
                ,"..."
                ,"#.#"
                ,"..#"};

            boolean good = false;

            for (int r = 0; r <= x-3; r++) {
                for (int c = 0; c <= 10-3; c++) {
                    if ((g[r].substring(c, c+3).equals(tspin[0]) || g[r].substring(c, c+3).equals(tspin[3]))
                    && g[r+1].substring(c, c+3).equals(tspin[1])
                    && g[r+2].substring(c, c+3).equals(tspin[2])) {
                        good = true;
                        break;
                    }
                }
                if (good) break;
            }

            out.println(good ? "T-Spin!!!" : "Missed it...");
        }
    }
}