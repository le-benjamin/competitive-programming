import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Mateusz {
    public static class Pair {
        int x, y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        for (int i = 0; i < tc; i++) {
            Set<Pair> s = new TreeSet<>(Comparator.comparing((Pair p) -> p.x).thenComparing(p -> p.y));
            int n = in.nextInt();
            while (n-->0) {
                int x = in.nextInt(), y = in.nextInt(), w = in.nextInt(), h = in.nextInt();
                for (int a = x; a < x+w; a++) {
                    for (int b = y; b < y+h; b++) {
                        s.add(new Pair(a, b));
                    }
                }
            }

            out.printf("Case #%d: The total area is %d.\n", i, s.size());
        }
    }
}