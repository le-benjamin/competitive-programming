import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Perry {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int n = in.nextInt(); in.nextLine();
            List<Integer> dishes = Arrays.stream(in.nextLine().split(" ")).map(Integer::valueOf).collect(Collectors.toList());
            int[] dp = new int[n]; // dp[i] = max value with dish i as last *possible* taken
            dp[0] = dishes.get(0);
            try {
                dp[1] = Math.max(dishes.get(1), dp[0]);
            } catch (Exception e) {}

            for (int i = 2; i < n; i++) {
                dp[i] = Math.max(dp[i-1], dp[i-2]+dishes.get(i));
            }

            out.println(dp[n-1]);
        }
    }
}