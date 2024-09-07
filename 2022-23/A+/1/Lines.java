import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Lines {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            out.printf("%d lines were sent\n", in.nextInt());
        }
    }
}