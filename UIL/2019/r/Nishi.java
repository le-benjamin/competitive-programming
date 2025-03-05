import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Nishi {
    public static int countSigFigs(String n) {
        String s = ""+n;
        if (s.contains("-")) {
            s = s.substring(1);
        }
        boolean has = s.contains(".");
        if (has) {
            int pos = s.split("[^0\\.]")[0].length();
            return s.length() - pos - 1 + (pos > s.indexOf(".") ? 1 : 0);
        }
        for (int i = s.length()-1; i>=0; i--) {
            if (s.charAt(i) != '0') {
                int ret = i + 1;
                return ret;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            String a = in.next();
            char o = in.next().charAt(0);
            String b = in.next();
            int sigfigs = Math.min(countSigFigs(a), countSigFigs(b));
            double ret = 0;
            if (o == 'X') {
                ret = Double.parseDouble(a)*Double.parseDouble(b);
            }
            else {
                ret = Double.parseDouble(a)/Double.parseDouble(b);
            }
            String str = String.format(String.format("%%.%de", sigfigs-1), ret);
            
            out.printf("%sE%d\n", str.substring(0, str.indexOf("e")), Integer.parseInt(str.substring(str.indexOf("e")+2)));
        }
    }
}