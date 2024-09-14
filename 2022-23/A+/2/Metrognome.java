import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Metrognome {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int n = in.nextInt();
            BigInteger ret = BigInteger.ONE;
            while (n-->0) {
                BigInteger Gi = new BigInteger(in.next());
                ret = ret.multiply(Gi).divide(ret.gcd(Gi));
            }
            out.println(ret);
        }
    }
}