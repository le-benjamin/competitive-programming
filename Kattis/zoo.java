package kattis.zoo;

import java.util.Scanner;
import java.util.HashMap;
import java.util.TreeMap;

public class zoo {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int caseNum = 1;



        while (n != 0) {
            in.nextLine();
            HashMap<String, Integer> species = new HashMap<String, Integer>();

            // could just use treemap from beginning

            for (int i = 0; i < n; i++) {
                String animal[] = in.nextLine().split(" ");
                String type = animal[animal.length-1].toLowerCase();

                if (species.containsKey(type)) {
                    species.put(type, species.get(type)+1);
                } else species.put(type, 1);
            
            }

            TreeMap<String, Integer> sorted = new TreeMap<>();

            sorted.putAll(species);

            System.out.println("List " + caseNum + ":");

            for (String x : sorted.keySet()) {
                System.out.println(x + " | " + species.get(x));
            }
            n = in.nextInt();
            caseNum++;
        }

        in.close();
    }
}
