import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Rosin {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int n = in.nextInt(); in.nextLine();
            List<Integer> coins = Arrays.stream(in.nextLine().split(" "))
                .map(Integer::valueOf)
                .collect(Collectors.toList());
            Collections.sort(coins);
            int c = in.nextInt();

            int[] dp = new int[c+1];
            Arrays.fill(dp, 999999);
            dp[0] = 0;
            for (int i = 1; i <= c; i++) {
                for (var coin : coins) {
                    if (coin > i) break;
                    dp[i] = Math.min(dp[i], dp[i-coin]+1);
                }
            }

            if (dp[c] >= 999999) out.println("No rosin for you! Come back in one year!");
            else out.println(dp[c]); 
        }
    }
}