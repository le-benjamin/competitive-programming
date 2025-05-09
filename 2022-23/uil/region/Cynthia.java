import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Cynthia {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int w = in.nextInt(), x = in.nextInt(), y = in.nextInt();
            out.printf("%,.2f\n", Math.max(w*(x+y)/2.0, Math.max(x*(w+y)/2.0, y*(w+x)/2.0)));
        }
    }
}