import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Renata {
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("renata.dat"));
		in.nextInt();
		int iters = 1;
		while (in.hasNextInt()) {
			int size = in.nextInt();
			int[][] v = new int[size][size];
			int score = 0; 
			for (int out = 0; out < size; out++) {
				for (int inn = 0; inn < size; inn++) {
					v[out][inn] = in.nextInt();
				}
			}
			int times = in.nextInt();
			for (int t = 0; t < times; t++) {
				score += v[in.nextInt()-1][in.nextInt()-1];
			}
			System.out.println(iters + ": " + score);
			iters++;
		}


		in.close();
	}

}
