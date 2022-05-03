import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Carolina{
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File("carolina.dat"));
			
		double sum = 0;
		double preSum = 0;

		while (in.hasNextLine()) {
			double a = in.nextDouble();
			preSum += a;
			String b = in.nextLine();
			double tax = Math.round((a*.0825) * 100) / 100.0;
			sum += a+tax;
			out.printf("$%.2f + $%.2f = $%.2f", a, tax, a+tax);
			out.println(b);
		}
		in.close();

		out.printf("$%.2f + $%.2f = $%.2f Combined Single Purchase", preSum, preSum*0.0825, preSum+(preSum*0.0825));
		out.println();
		out.printf("$%.2f Sum of Individual Purchases", sum);
	}

}
