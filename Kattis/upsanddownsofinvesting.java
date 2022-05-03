package kattis; // only here because intellisense likes to whine

import java.util.Scanner;

public class jtemplate {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

	int s = in.nextInt(), n = in.nextInt(), m = in.nextInt();

	int[] prices = new int[s];

	for (int i = 0; i < s; i++) prices[i] = in.nextInt();




        in.close();
    }
}
