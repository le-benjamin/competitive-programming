import java.util.*;
import java.lang.*;
import java.io.*;
import static java.lang.System.*;

public class pr91 {
	public static void main (String[] args) throws IOException {
			// Scanner in = new Scanner(new File("t.dat"));
			
			Scanner in = new Scanner(System.in);

			int t = in.nextInt();
			
			in.nextLine();
			for (int c = 0; c < t; c++) {
				String[] line = in.nextLine().split(" ");
				String output = line[0];
				
				for (int i = 1; i < line.length; i++) {
					int len = output.length();
					if (len > 3) {
						if (output.charAt(len-2) != '\'' && !output.substring(len-4).equals(" not") && !output.substring(len-3).equals(" is")) {
							if (line[i].equals("is") || line[i].equals("not")) {
								if (line[i].equals("is")) output+= "\'s";
								else output += "n\'t";
								continue;
							}
						}
					}
					else if (!output.equals("not") && !output.equals("is")) {
						if (len == 2) {
							if (line[i].equals("is") || line[i].equals("not")) {
								if (line[i].equals("is")) output+= "\'s";
								else output += "n\'t";
								continue;
							}
						}
						if (len==1) {
								if (line[i].equals("is") || line[i].equals("not")) {
									if (line[i].equals("is")) output+= "\'s";
									else output += "n\'t";
									continue;
								}

						}
					}	
							
					output += " " + line[i];
				}
				out.println(output);
			}
	}
}
