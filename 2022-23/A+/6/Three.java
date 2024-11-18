import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Three {

    public static void main(String[] args) {
        Map<String, Integer> m = new HashMap<>();
        m.put("A", 0);
        m.put("A#", 1);
        m.put("Bb", 1);
        m.put("B", 2); 
        m.put("Cb", 2); 
        m.put("C", 3); 
        m.put("B#", 3); 
        m.put("C#", 4); 
        m.put("Db", 4); 
        m.put("D", 5); 
        m.put("D#", 6); 
        m.put("Eb", 6); 
        m.put("E", 7); 
        m.put("Fb", 7); 
        m.put("F", 8); 
        m.put("E#", 8); 
        m.put("F#", 9); 
        m.put("Gb", 9); 
        m.put("G", 10); 
        m.put("G#", 11); 
        m.put("Ab", 11);

        List<Integer> arr = Arrays.asList(0,3,4,5,7,8,9);
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            String a = in.next(), b = in.next(), c = in.next();
            out.printf("%s %s %s | %d %d %d ", a, b, c, Math.abs(m.get(a)-m.get(b)), Math.abs(m.get(c)-m.get(b)), Math.abs(m.get(a)-m.get(c)));
            if (arr.contains(Math.abs(m.get(a)-m.get(b))) 
                && arr.contains(Math.abs(m.get(c)-m.get(b)))
                && arr.contains(Math.abs(m.get(a)-m.get(c)))) {
                    out.println("Great!");
            }
            else out.println("AHHHHHHH");
        }
    }
}