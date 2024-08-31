import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Norman {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int n = in.nextInt();
            if (n == 13) out.println("BAD LUCK");
            else if (n%2 == 1) out.println("ODD");
            else out.println("EVEN");

        }
    }
}