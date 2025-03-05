import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Education {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += in.nextInt();
            }
            out.println(sum);
        }
    }
}
