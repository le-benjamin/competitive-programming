import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Eva {
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("eva.dat"));
		in.nextInt();
		int x = 1;
		while (in.hasNextInt()) {
			System.out.println("Start of Triangle #" + x);
			x++;
			int height = in.nextInt();
			for (int line = 1; line <= height; line++) {
				int stuff = 0;
				for (int point = 1; stuff < line * 2 - 1; point++) {
					if (point < height - line + 1) {
						System.out.print(" ");
					} else {
						System.out.print("*");
						stuff++;
					}			
				}
				System.out.println();
			}
			System.out.println("End of Triangle #" + (x-1));
		}
		


		in.close();
	}

}
