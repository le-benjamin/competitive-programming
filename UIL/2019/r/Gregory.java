import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Gregory {
    public static char getCat(char c) {
        if (c >= 'A' && c <= 'Z') return 'u';
        if (c >= 'a' && c <= 'z') return 'l';
        if (c >= '0' && c <= '9') return 'd';
        return 's';
    }

    public static String getRating(int score) {
        if (score <= 0) return "UNACCEPTABLE";
        else if (score <= 15) return "WEAK";
        else if (score <= 30) return "FAIR";
        else if (score <= 45) return "GOOD";
        else return "STRONG";
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String freq = in.next(), symbols = in.next();
        Set<String> common = new HashSet<>();
        for (int i = 0; i < 10; i++) {
            Scanner line = new Scanner(in.next());
            line.useDelimiter(",");
            for (int j = 0; j < 10; j++) {
                common.add(line.next().toLowerCase());
            }
        }
        while (in.hasNext()) {
            String pass = in.next();
            out.printf("%s:", pass);
            int score = 0;
            int catCount = 0;
            boolean checkedSymbols = false;
            if (pass.split("[a-z]", -1).length > 1) { catCount++; }
            if (pass.split("[A-Z]", -1).length > 1) { catCount++; }
            if (pass.split("[\\d]", -1).length > 1) { catCount++; }

            if (common.contains(pass.toLowerCase()) || pass.length() < 8) {
                score = 0;
            } else {
                for (int i = 0; i < pass.length(); i++) {
                    if (freq.indexOf( (""+pass.charAt(i)).toUpperCase() ) < 13 && freq.indexOf( (""+pass.charAt(i)).toUpperCase() ) > -1) score++;
                    else if (freq.indexOf( (""+pass.charAt(i)).toUpperCase() ) >= 13) score+=2;
                    else if (getCat(pass.charAt(i)) == 'd') score += 2;
                    else if (getCat(pass.charAt(i)) == 's') { 
                        if (!checkedSymbols) catCount++;
                        checkedSymbols = true;
                        score += 3;
                    }

                    if (i >= 8) score += 2;
                    if (i > 0 && getCat(pass.charAt(i)) != getCat(pass.charAt(i-1))) score += 2;
                    if (i > 0 && pass.charAt(i) == pass.charAt(i-1)) score--;
                    if (i > 1) {
                        if (pass.charAt(i-1) == pass.charAt(i)-1 && pass.charAt(i-2) == pass.charAt(i)-2) score -= 5; 
                    }
                    
                }
                if (catCount == 4) score += 5;
                if (catCount < 3) score = 0;
            }
            out.printf("%d:%s\n", score, getRating(score));

        }
    }
}