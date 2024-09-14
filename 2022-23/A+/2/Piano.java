import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Piano {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int n = in.nextInt();
            char[] road = in.next().toCharArray();
            int ret = 0;
            for (int i = 2; i < n; i++) {
                if (road[i] == '.' && road[i-1] == '.' && road[i-2] == '.') {
                    ret++;
                    road[i] = '-';
                }
            }
            out.println(ret);
        }
    }
}