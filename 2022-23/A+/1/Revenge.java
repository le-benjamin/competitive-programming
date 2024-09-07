import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Revenge {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt(); in.nextLine();
        while (tc-->0) {
            String line = in.nextLine();
            out.println(scramble(line));
        }
    }

    public static String scramble(String line) {
        if (line.length() == 1) return line;
        int m = line.length()/2;
        String rev = (new StringBuilder(line)).reverse().toString();
        return scramble(rev.substring(0, m)) + scramble(rev.substring(m));
    }
}