import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class DayJob {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        HashSet<String> hs = new HashSet<>();
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            String food = in.next();
            String tag = in.next();
            if (tag.equals("GMO") && !hs.contains(food)) {
                hs.add(food);
            }
        }
        out.printf("%d food(s) contain(s) GMOs\n", hs.size());
    }
}

