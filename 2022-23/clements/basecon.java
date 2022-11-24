import java.util.*;
import static java.lang.System.*;

public class basecon {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        
        while (n-- > 0) {
            String base = in.next();
            String num = in.next();
            
            int sb = 10;
            if (base.equals("D")) 
                sb = 10;
            if (base.equals("H")) 
                sb = 16;
            if (base.equals("O")) 
                sb = 8;
            if (base.equals("B")) 
                sb = 2;
            
            int nu = Integer.parseInt(num, sb);
            out.printf("%s %s %s %s\n", Integer.toString(nu, 10), Integer.toString(nu, 16), Integer.toString(nu, 8), Integer.toString(nu, 2));
        }
        in.close();
    }
}