package Kattis;

import java.util.Scanner;

public class fizzbuzz2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt(), m = in.nextInt();
        
        String[] fizzbuzz = new String[m];
        for (int i = 1; i <= m; i++) {
            String out = "";
            if (i%3 == 0) out += "fizz";
            if (i%5 == 0) out += "buzz";
            if (out.length() < 1) out += i;
            fizzbuzz[i-1] = out;
        }

        in.nextLine();

        int bestCand = 0, bestScore = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            String[] words = in.nextLine().split(" ");

            int score = 0;

            for (int j = 0; j < m; j++) {
                if (words[j].equals(fizzbuzz[j])) score++;
                else score--;
            }

            if (score > bestScore) {
                bestCand = i+1;
                bestScore = score;        
            }
        }
        in.close();
        
        System.out.println(bestCand);
    }
}