import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Conflict {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy");
            Calendar date = Calendar.getInstance();
            try{
                date.setTime(sdf.parse(in.next()));
            } catch (Exception e) {}
            date.add(Calendar.DAY_OF_YEAR, in.nextInt());
            out.println(sdf.format(date.getTime()));
        }
    }
}