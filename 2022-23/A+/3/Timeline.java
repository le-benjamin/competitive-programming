import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Timeline {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            in.next();
            int d = in.nextInt();
            SimpleDateFormat sdf = new SimpleDateFormat("M/d/yyyy");
            Calendar c = Calendar.getInstance();
            try {
                c.setTime(sdf.parse("07/01/1975"));
            } catch (Exception e) {};
            c.add(Calendar.DAY_OF_YEAR, d*12);
            out.println(sdf.format(c.getTime()));
        }
    }
}