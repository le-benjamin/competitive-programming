import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Concerto {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt(); in.nextLine();
        while (tc-->0) {
            int cnt = in.nextLine().split("minor", -1).length-1;
            out.println(cnt > 2 ? "It's over Vee Valdee! I have the high ground!" : "You underestimate my music!");
        }
    }
}