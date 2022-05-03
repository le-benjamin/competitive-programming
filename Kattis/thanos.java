// TLE
package kattis.thanos;

import java.util.Scanner;

public class thanos {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();

        for (int i = 0; i < t; i++) {
            int p = in.nextInt(), r = in.nextInt(), f = in.nextInt();
            int counter = 0;
            while (p <= f) {
                counter++;
                p *= r;
            }
            System.out.println(counter);
        }

        in.close();
    }
}