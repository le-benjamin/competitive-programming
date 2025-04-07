import java.util.*;
public class p07 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int x = in.nextInt(); in.nextLine();
            int out = 0, weight = 0, w = 1;
            while (x-->0) {
                String[] arr = in.nextLine().split(" ");
                if (arr[0].equals("LOW")) w = 1;
                if (arr[0].equals("MEDIUM")) w = 2;
                if (arr[0].equals("HIGH")) w = 3;
                out += Integer.parseInt(arr[1])*w;
                weight += w;
            }
            System.out.println(Math.round(10.0*out/weight));
        }
    }
}
