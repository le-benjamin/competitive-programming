import static java.lang.System.*;
import java.util.*;
import java.io.*;

public class Main {
    
    public static void main (String args[]) throws IOException {
        Scanner in = new Scanner(new File("pr92.dat"));

        int n = in.nextInt();

        while (n-- > 0) { 
            HashMap<Character, ArrayList<Character>> paths = new HashMap<>();
            HashMap<Character, Integer> values = new HashMap<>();
            int points = 0;

            char[] st = in.next().toCharArray();
            HashMap<Character, Boolean> stops = new HashMap<>();
            for (char c : st)
                stops.put(c, true);
            
            in.nextLine();

            String[] areas = in.nextLine().split(" ");
            
            char start = areas[0].charAt(0);

            for (String s : areas) {
                char origin = s.charAt(0);
                boolean isCapital = Character.isUpperCase(origin);
                int val = 0;
                int i = 1;
                for (; i < s.length() && Character.isDigit(s.charAt(i)); i++) {
                    val *= 10;
                    val += Character.digit(s.charAt(i), 10);
                }
                ArrayList<Character> a = new ArrayList<>();
                if (i < s.length())
                    for (char c : s.substring(i).toCharArray())
                        a.add(c);
                
                paths.put(origin, a);
                values.put(origin, (isCapital)?val:val*-1);
            }
            points += values.get(start);

            out.println(values + " P = " + points);

        }

        in.close();
    }
}
