import java.util.*;
import java.io.*;

class Arusha {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();

        int T = io.nextInt();

		while (T-->0) {
			String original = io.next();
			String instruct = io.next();

			while (instruct.length() > 0) {
				if (instruct.charAt(0) == 'L') {
					original = L(original);
				} else {
					original = R(original);
				}
				instruct = instruct.substring(1);
			}

			io.println(original);

		}
		

        io.close();
    }

	public static String L(String s) {
		return s.substring(1) + s.charAt(0);
	}

	public static String R(String s) {
		return s.charAt(s.length()-1) + s.substring(0, s.length()-1);

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