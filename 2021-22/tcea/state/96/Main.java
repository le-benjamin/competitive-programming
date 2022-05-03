import static java.lang.System.*;
import java.util.*;
import java.io.*;

public class Main {

    public static boolean eval(HashMap<String, Boolean> vals, String expression) {
        if (expression.indexOf(" or ") != -1) {
            return eval(vals, expression.substring(0, expression.indexOf(" or "))) || eval(vals, expression.substring(expression.indexOf(" or ") + 4));
        }
        if (expression.indexOf(" and ") != -1) {
            return eval(vals, expression.substring(0, expression.indexOf(" and "))) && eval(vals, expression.substring(expression.indexOf(" and ") + 5));
        }
        if (expression.indexOf("not ") != -1) {
            return !eval(vals, expression.substring(expression.indexOf("not ")+4));
        }

        if (expression.equals("true")) return true;
        if (expression.equals("false")) return false;
        return vals.get(expression);
    }
    
    public static void main (String args[]) throws IOException {
        Scanner in = new Scanner(new File("pr96.dat"));

        int n = in.nextInt();
        in.nextLine();

        while (n-- > 0) {
            String exp = in.nextLine().trim();
            HashMap<String, Boolean> values = new HashMap<>();

            for (String s : exp.split(" "))
                if (s.length() == 1)
                    values.put(s, true);

            ArrayList<String> assignments = new ArrayList<>();
            
            String a = in.nextLine().trim();
            while (!a.equals("end")) {
                assignments.add(a);
                a = in.nextLine().trim();
            }

            int count = 0;

            while (eval(values, exp) && count <= 10) {
                for (String s : assignments) {
                    values.put(s.substring(0, 1), eval(values, s.substring(2)));
                }
                count++;
            }

            out.println(count <= 10 ? count : "infinite");

        }
    }
}
