import java.util.*;
import java.io.*;

class Fernando {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();

        int t = io.nextInt();
		while(t-->0) {
			int a = io.nextInt(), b = io.nextInt();
			TreeSet<Integer> s = new TreeSet<>();
			for (int i = 1; i <= Math.sqrt(a); i++) {
				if (a%i != 0) continue;
				if (!(""+i).contains(""+b)) s.add(i);
				if (a/i != i && !(""+(a/i)).contains(""+b)) s.add(a/i);
			}
			if (s.isEmpty()) io.print("NONE");
			else for (int i : s) io.print(i + " ");
			io.println();
		}

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