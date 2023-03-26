import java.io.*;
import java.util.*;

public class Vanessa {

    public static void main(String[] args) throws IOException{
        // Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new File("vanessa.dat"));
        int n = in.nextInt(); in.nextLine();
        while (n-- > 0) {
            String[] tempa = in.nextLine().split(",");
            int goal = in.nextInt();
            int[] coins = new int[tempa.length+1];
            for (int i = 0; i < tempa.length; i++) coins[i] = Integer.parseInt(tempa[i]);
            Arrays.sort(coins);
            int[][] dp = new int[goal+5][105];
            dp[0][0] = 1;
            for (int lim = 1; lim <= goal; lim++) {
                for (int c : coins) {
                    if (c > lim) break;
                    for (int i = 0; i <= c; i++) {
                        dp[lim][c] += dp[lim-c][i];
                    }
                }
            }
            
            int total = 0;
            for (var x : dp[goal]) total += x;
            System.out.println(total);
            in.nextLine(); in.nextLine();
        }
    }
}