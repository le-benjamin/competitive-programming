import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Ulysses {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int l = in.nextInt();
            int cnt = 0;
            for (int i = 1; i <= l; i++) {
                for (int j = i; j <= l; j++) {
                    for (int k = j; k <= l; k++)
                    if (i+j > k) {
                        cnt++;
                    }
                }
            }
            out.println(cnt);
        }
    }
}