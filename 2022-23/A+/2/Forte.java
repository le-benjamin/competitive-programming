import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Forte {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int d = in.nextInt();
            if (d < 0) out.print("pian");
            else out.print("fort");
            
            if (d == -1) out.println("o");
            else if (d == 1) out.println("e");
            else {
                d = Math.abs(d)-1;
                while (d-->0) out.print("iss");
                out.println("imo");
            }
        }
    }
}