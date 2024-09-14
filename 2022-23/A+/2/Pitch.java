import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Pitch {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt(); in.nextLine();
        while (tc-->0) {
            String[] note = in.nextLine().split(" ");
            if (note[1].equals("Sharp")) {
                out.println((char)((note[0].charAt(0)-'A'+7+1)%7+'A')  + " Flat");
            } else {
                out.println((char)((note[0].charAt(0)-'A'+7-1)%7+'A')  + " Sharp");
            }
        }
    }
}