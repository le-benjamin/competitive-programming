import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Ricardo {
    public static long eval(String a) {
        if (a.charAt(0) == '(') 
            a = a.substring(1, a.length()-1);
        String[] arr = a.split(",");
        if (arr.length == 1) {
            arr = a.split("|");
            if (arr.length == 1) 
                return 1;
            long total = 0;
            for (String b : arr) 
                total += eval(b);
            return total;
        }
        long product = 1;
        for (String b : arr)
            product *= eval(b);
        return product;
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("ricardo.dat"));
        int t = in.nextInt();

        for (int i = 1; i <= t; i++) {
            String a = in.next();
            out.printf("Case #%d: %d\n", i, eval(a));
        }
    }
}
