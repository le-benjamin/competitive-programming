import java.util.*;

class Neo {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc --> 0) {
            int N = in.nextInt();
            int M = in.nextInt();
            ArrayList<Integer> cats = new ArrayList<>();
            int max = 0;
            for (int i = 0; i < N; i++) {
                cats.add(in.nextInt());
                max = Math.max(max, cats.get(i));
            }
            String line = "";
            for (int n: cats) {
                if (n + M >= max) {
                    line += " 1";
                }
                else {
                    line += " 0";
                }
            }
            System.out.println(line.trim());


        }
    }
}