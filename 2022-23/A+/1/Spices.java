import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Spices {
    public static class Spice {
        public String name, color;
        public int m, rating;

        public Spice(String name, int m, int rating, String color) {
            this.name = name;
            this.m = m;
            this.rating = rating;
            this.color = color;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        List<Spice> spices = new ArrayList<>();
        int tc = in.nextInt();
        while (tc-->0) {
            spices.add(new Spice(in.next(), in.nextInt(), in.nextInt(), in.next()));
        }
        Collections.sort(spices, 
            Comparator.comparing((Spice s) -> -s.rating)
                .thenComparing(s -> Map.of("White", 1, "Red", 2, "Brown", 3, "Orange", 4, "Blue", 5).getOrDefault(s.color, 6))
                .thenComparing(s -> -s.m)
                .thenComparing(s -> s.name));
        
        spices.forEach((Spice s) -> System.out.println(s.name));
    }
}