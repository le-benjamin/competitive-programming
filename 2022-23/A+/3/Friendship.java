import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Friendship {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt(); in.nextLine();
        while (tc-->0) {
            List<Integer> list = Arrays.stream(in.nextLine().split(" ")).map(Integer::valueOf).collect(Collectors.toList());
            Collections.sort(list);
            out.printf("Hottest Temp - %d\n", list.get(4));
        }
    }
}