import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Bass {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int N = in.nextInt(), q = in.nextInt(), T = in.nextInt();
            out.printf("%.2f\n", (Math.log(Math.pow(N, q))/Math.log(2))/(Math.sqrt(Math.abs(42*Math.sin(T)))) );
        }
    }
}