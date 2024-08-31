import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Jed {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            String s = in.next();
            char[][] g = new char[s.length()+1][s.length()+1];
            for (var x : g) Arrays.fill(x, ' ');
            for (int i = 0; i < s.length(); i++) g[0][i] = g[i][s.length()] = g[s.length()][s.length()-i] = g[s.length()-i][0] = s.charAt(i);
            for (var x : g) {
                for (var y : x) out.print(y);
                out.println();
            }
            out.println();
        }
    }
}