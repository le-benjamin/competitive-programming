import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Perfect {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int x = in.nextInt();
            int cnt = 0;
            while (x-->0) {
                cnt += in.next().split("#", -1).length - 1;
            }
            out.println(cnt%2 == 1 ? "Just give up already!" : "Further investigation is needed.");
        }
    }
}