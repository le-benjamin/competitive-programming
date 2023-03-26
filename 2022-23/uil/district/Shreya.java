import java.io.*;
import java.util.*;

public class Shreya {

    public static void main(String[] args) throws IOException {
        // Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new File("shreya.dat"));
        int n = in.nextInt();
        while (n-- > 0) {
            in.nextLine();
            String[] tempa = in.nextLine().split(" ");
            int lim = in.nextInt();
            int[] coins = new int[tempa.length+1];
            for (int i = 0; i < tempa.length; i++) coins[i] = Integer.parseInt(tempa[i]);
            Arrays.sort(coins);
            boolean[] dp = new boolean[lim+1];
            dp[0] = true;
            
            for (var c : coins) {
                for (int goal = lim; goal >= 0; goal--) {
                    if (c <= goal && dp[goal-c]) dp[goal] = true;
                }
            }
            
            if (dp[lim]) System.out.println("Business as usual.");
            else System.out.println("Dine and Dash.");
        }
    }
}