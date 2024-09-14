import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Quartet {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt(); in.nextLine();
        while (tc-->0) {
            in.nextLine();
            int ret = 0;
            for (int i = 0; i < 4; i++) {
                List<Integer> list = Arrays.stream(in.nextLine().split(" "))
                    .map(Integer::valueOf)
                    .collect(Collectors.toList());
                Collections.sort(list);
                ret += list.get(list.size()-1);
            }
            out.println(ret);
        }
    }
}