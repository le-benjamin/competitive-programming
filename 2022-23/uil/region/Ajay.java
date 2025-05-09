import java.util.*;
import java.io.*;

class Ajay {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
		
		io.println("             -----TRAPEZOID-----");
		io.println("            /                   \\");
		io.println("           /                     \\");
		io.println("          T                       T");
		io.println("         R                         R");
		io.println("        A                           A");
		io.println("       P                             P");
		io.println("      E                               E");
		io.println("     Z                                 Z");
		io.println("    O                                   O");
		io.println("   I                                     I");
		io.println("  D                                       D");
		io.println(" /                                         \\");
		io.println("/                                           \\");
        io.println("------------------TRAPEZOID------------------");

        io.close();
    }

    static class Kattio extends PrintWriter {
        private BufferedReader r;
		private StringTokenizer st;
        
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}
        
		public Kattio(String problemName) throws IOException {
			super(problemName + ".out");
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}
        
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
		public String nextLine() { 
            if (st != null && st.hasMoreTokens()) 
            { String out = ""; while (st.hasMoreTokens()) out += st.nextToken() + ' '; return out; }
            try { return r.readLine(); } catch (Exception e) { return null; } 
        }
	}
}