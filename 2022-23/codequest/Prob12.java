import java.util.*;
import java.io.*;
import java.time.LocalDateTime;

public class Prob12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int iter = sc.nextInt(); sc.nextLine();
        for(int i = 0;i<iter;i++) {
            int r = sc.nextInt();
            int c = Integer.parseInt(sc.nextLine().trim());
            Map<String,String> m = new HashMap<>();
            for(int j =0 ;j<r;j++) {
                String[] temp = sc.nextLine().split(": ");
                m.put(temp[0],temp[1]);
            }
            String s = "";
            for(int j = 0;j<c;j++) s += sc.nextLine()+"\n";
            s = s.trim();
            for(String x : m.keySet()) s = s.replace("["+x+"]",m.get(x));
            System.out.println(s);
        }
    }
}