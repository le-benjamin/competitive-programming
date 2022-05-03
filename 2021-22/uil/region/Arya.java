import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Arya {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("arya.dat"));
        int t = in.nextInt();

        while (t-- > 0) {
            int range = in.nextInt();
            int goal = in.nextInt();
            int l = 1, r = range, m = (l+r)/2;
            out.println(l + "-" + m + "-" + r);
            if (m != goal) {
                while (m != goal) {
                    if (m < goal) {
                        l = m+1;
                        m = (l+r)/2;
                    } else {
                        r = m-1;
                        m = (l+r)/2;
                    }
                    
                    out.println(l + "-" + m + "-" + r);
                }
            }
            out.println("GOT IT!!!");
        }
    }
}
