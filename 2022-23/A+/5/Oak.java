import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Oak {
    public static class Pokemon {
        public String name, a, b, c;

        public Pokemon(String name, String a, String b, String c) {
            this.name = name;
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int n = in.nextInt();
            List<Pokemon> list = new ArrayList<>();
            while (n-->0) {
                list.add(new Pokemon(in.next(), in.next(), in.next(), in.next()));
            }

            Collections.sort(list, Comparator
                .comparing((Pokemon p) -> p.name)
                .thenComparing(p -> p.a)
                .thenComparing(p -> p.b)
                .thenComparing(p -> p.c));
            
            for (var x : list) {
                out.println(x.name);
            }
        }
    }
}