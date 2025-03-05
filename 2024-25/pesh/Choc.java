import java.io.*;
import java.text.*;
import java.util.*;
import static java.lang.System.*;

public class Choc {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            SimpleDateFormat sdf = new SimpleDateFormat("M/d/yyyy");
            Calendar c = Calendar.getInstance();
            try {
                c.setTime(sdf.parse("7/21/2025"));
            } catch (Exception e) {};
            c.add(Calendar.DAY_OF_YEAR, x);
            out.println(sdf.format(c.getTime()));
        }
    }
}
