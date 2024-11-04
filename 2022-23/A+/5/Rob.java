import java.util.*;

class Rob {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc --> 0) {

            int n = in.nextInt();
            int m = in.nextInt();

            PriorityQueue<Integer> q = new PriorityQueue<>();
            for (int i = 0; i < n; i++) {
                q.add(in.nextInt());
            }

            int ans = 0;
            int i = 0;
            while (ans < m) {
                ans+= q.poll();
                i++;
            }

            System.out.println(i-1);

        }
    }
}