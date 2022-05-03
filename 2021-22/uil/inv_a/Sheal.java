import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Sheal {
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File("sheal.dat"));

		int t = in.nextInt();

		for (int ca = 0; ca < t; ca++) {
			char[] word = in.next().toCharArray();
			int k = in.nextInt();

			Arrays.sort(word);

			
		}

		in.close();
	}

}
