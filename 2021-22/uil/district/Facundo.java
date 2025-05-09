import java.util.*;
import java.io.*;

class Facundo {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();

		int T = io.nextInt();

		while (T-->0) {
			String original = io.next();
			int times = io.nextInt();
			
			while (times--> 0) {
				original = shuffle(original);
			}

			io.println(original);
		}

        io.close();
    }

	public static String shuffle(String s) {
		String out = "";
		
		String a = "";
		String b = "";

		if (s.length() % 2 ==0) {
			a = s.substring(0, s.length()/2);
			b = s.substring(s.length()/2);
		} else {
			a = s.substring(0, s.length()/2 + 1);
			b = s.substring(s.length()/2 + 1);
		}

		while (a.length() > 0) {
			out = a.substring(a.length() - 1) + out;
			a = a.substring(0, a.length() - 1);
			if (b.length() > 0) {
				out = b.substring(b.length() - 1) + out;
				b = b.substring(0, b.length() - 1);
			}

		}
		return out;
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