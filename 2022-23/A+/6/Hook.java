import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Hook {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            double d = in.nextDouble(), h = in.nextDouble();
            double t = h/100;
            h += t*50;
            out.println(Math.atan(h/d)/Math.PI*180);
        }
    }
}