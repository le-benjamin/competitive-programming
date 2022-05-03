import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Tom{
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File("tom.dat"));

		in.nextInt();
		while (in.hasNext()) {
			int total = 0;
			TreeMap<String, Integer> map = new TreeMap<String, Integer>();
			for (int a = 97; a < 123; a++) {
				map.put("" + (char)a, 1);
			}
			for (char c : in.next().toCharArray()) {
				String s = "" + c;
				total+= map.get(s);
				map.get(s) += 1;
			}
			System.out.println(total);
		}



		in.close();
	}

}
