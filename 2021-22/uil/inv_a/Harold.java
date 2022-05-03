import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Harold {
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File("harold.dat"));

		int n = in.nextInt();

		for (int ind = 0; ind < n; ind++) {

			int i = in.nextInt();

			int p = (""+i).length()-1;
			double m = i/Math.pow(10,p);

			out.printf("%d=", i);
			if ((m*10)%10 == 0) out.print((int)m);
			else out.print(m);
			out.printf("*10^%d\n", p);
		}


		in.close();
	}

}
