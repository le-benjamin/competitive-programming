import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Store {
    public static int[] canBuy(int amt, int[] cnts) {
        int[] vals = { 100, 25, 10, 5, 1 };
        int[] ret = { 0, 0, 0, 0, 0 };
        for (int i = 0; i < 5; i++) {
            while (amt > vals[i] && cnts[i] > ret[i]) {
                ret[i]++;
                amt -= vals[i];
            }
        }

        if (amt != 0) {
            for (int i = 0; i < 5; i++) {
                ret[i] = 0;
            }
        }

        return ret;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int x = in.nextInt();
            boolean flag = false;
            int cnt = 0;
            int[] cnts = new int[5];
            int[] vals = { 100, 25, 10, 5, 1 };
            for (int i = 0; i < 5; i++) cnts[i] = in.nextInt();
            for (int i = 0; i < x; i++) {
                in.next();
                double amt = in.nextDouble();
                int[] ret = canBuy((int)(amt*100), cnts);
                for (int j = 0; j < 5; j++) {
                    if (ret[j] > 0) {
                        flag = true;
                        cnt++;
                    }
                    cnts[j] -= ret[j];
                }
            }
            out.println(cnt == x ? "Got all items" : (flag ? "Come again" : "Mission failed"));
        }
    }
}