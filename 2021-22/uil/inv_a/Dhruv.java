import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Dhruv {
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File("dhruv.dat"));
		String[] names = new String[8];
		int[] codes = new int[8];
		for (int x = 0; x < 8; x++) {
			names[x] = in.next();
			codes[x] = in.nextInt();
		}
		in.nextInt();
		while(in.hasNextInt()) {
			int num = in.nextInt();
			if (num < 535 || num > 1605) {
				System.out.println("BAD INPUT");
			} else {
				int closest = 0;
				for (int x = 1; x < 8; x++) {
					if (Math.abs(num-codes[closest]) >= Math.abs(num - codes[x])) {
						closest = x;
					}
				}
				System.out.println(names[closest]);
			}
		}


		in.close();
	}

}
