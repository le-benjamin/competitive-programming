import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Blox {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            in.nextLine();
            List<Integer> heights = Arrays.stream(in.nextLine().split(" ")).map(Integer::valueOf).collect(Collectors.toList());
            Collections.sort(heights);
            int target = in.nextInt();
            boolean[] dp = new boolean[target+1];
            dp[0] = true;
            for (var height : heights) {
                for (int i = height; i < target; i++) {
                    dp[i] |= dp[i-height];
                }
            }

            out.println(dp[target] ? "Blox be crazy" : "Not on my Blox");
        }
    }
}