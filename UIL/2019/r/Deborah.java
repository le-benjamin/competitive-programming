import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Deborah {
    public static class Item {
        String name;
        boolean fav;
        int size;
        List<String> inside;

        public Item(String name, boolean fav, int size) {
            this.name = name;
            this.fav = fav;
            this.size = size;
            inside = new ArrayList<>();
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            HashMap<String, Item> hm = new HashMap<>();
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                Item cur = new Item(in.next(), in.nextInt() == 1, in.nextInt());
                for (int j = 0; j < cur.size; j++) {
                    cur.inside.add(in.next());
                }
            }
        }
    }
}