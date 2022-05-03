import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Ishika {
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File("ishika.dat"));

		int n = in.nextInt();

		for (int i = 0; i < n; i++) {
			int t = in.nextInt();

			int[] arr = new int[t];

			for (int j = 0; j < t;j++) arr[j] = in.nextInt();

			int ans = Integer.MAX_VALUE;

			for (int a = 0; a < t; a++) {
				for (int b = a+1; b < t; b++) {
					int c = arr[a] + arr[b];
					if (c >= 20 && c < ans) ans = c;
				}
			}

			if (ans == Integer.MAX_VALUE) {
				out.println("NOT POSSIBLE");
			} else out.println(ans);
		}



		in.close();
	}

}
