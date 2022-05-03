import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Juana {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("juana.dat"));
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            System.out.print("Test case #"+(i+1)+":");
            int r = sc.nextInt();
            int c = sc.nextInt();
            int[][] temp = new int[r][c];
            for (int j = 0; j < r; j++)
                for (int k = 0; k < c; k++)
                    temp[j][k] = sc.nextInt();
            int r1 = sc.nextInt();
            int c1 = sc.nextInt();
            int cp = sc.nextInt();
            int rp = sc.nextInt();
            if(r1 <= 0 || c1 <= 0 || rp+r1-1 > r || cp+c1-1 > c)
            {
                System.out.println(" Unable to extract requested size!");
                for(int j = 0;j<20;j++)
                    out.print("-");
                out.println();
                continue;
            }
            System.out.println();
            for(int j = 0;j<rp;j++) {
                for (int k = 0; k < cp; k++)
                    System.out.printf("%5d", temp[r1 + j-1][c1 + k-1]);
                System.out.println();
            }
            for(int j = 0;j<20;j++)
                out.print("-");
            out.println();
        }
    }
}
