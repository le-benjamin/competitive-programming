import java.util.*;

class Sarah {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc --> 0) {

            int i = in.nextInt();
            int t = in.nextInt();
            int s = in.nextInt();
            int l = in.nextInt();

            boolean add = true;
            while (t --> 0) {
                if (add) {
                    i += s;
                }
                else {
                    i -= s;
                }
                add = !add;
                if (i <= 0) {
                    System.out.println("Sad Sarah");
                    break;
                }
            }
            if (i > 0) {
                System.out.println("Happy Sarah");
            }

        }
    }
}