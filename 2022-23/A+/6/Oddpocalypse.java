import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Oddpocalypse {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int a = in.nextInt();
            if (Math.abs(a%2) == 1) out.println(a);
        }
    }
}