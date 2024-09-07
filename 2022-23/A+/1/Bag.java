import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Bag {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt(); 
        while (tc-->0) {
            String line = in.next();
            boolean good = true;
            int i = 0;
            for (; i+7 < line.length(); i += 7) {
                if (Arrays.stream(line.substring(i, i+7).split("")).collect(Collectors.toSet()).size() != 7) {
                    good = false;
                }
            }
            if (Arrays.stream(line.substring(i).split("")).collect(Collectors.toSet()).size() != line.length()-i) {
                good = false;
            }
            out.println(good ? "Valid bag" : "Invalid bag");
        }
    }
}