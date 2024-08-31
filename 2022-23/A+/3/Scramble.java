import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Scramble {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            String s = in.next();
            if (s.contains("m")) out.println("milk");
            else if (s.contains("g")) out.println("eggs");
            else out.println("wheat");
        }
    }
}