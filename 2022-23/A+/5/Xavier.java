import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Xavier {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt(); in.nextLine();
        while (tc-->0) {
            List<Integer> list = Arrays.stream(in.nextLine().split(" ")).map(Integer::valueOf).collect(Collectors.toList());
            Set<Integer> s = new HashSet<>();
            for (var x : list) {
                if (s.contains(x)) s.remove(x);
                else s.add(x);
            }
            out.println(s.toString());
        }
    }
}