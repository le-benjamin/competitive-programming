package USACO.Training.Chapter_4;

/*
ID: b.le611
PROG: buylow
LANG: JAVA
*/

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class buylow {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio("buylow");
        
        int n = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();

        int[] dp = new int[n];
        BigInteger[] cnt = new BigInteger[n];
        int[] next = new int[n];

        Map<Integer, Integer> vis = new HashMap<>();
        for (int i = n-1; i >= 0; i--) {
            if (!vis.containsKey(a[i])) next[i] = n;
            else next[i] = vis.get(a[i]);
            vis.put(a[i], i);
        }

        dp[0] = 1;
        cnt[0] = BigInteger.ONE;

        for (int i = 1; i < n; i++) {
            int mx = 0;
            BigInteger mxc = BigInteger.ONE;
            
            for (int j = i-1; j >= 0; j--) {
                if (a[j] <= a[i]||next[j] < i) continue;
                if (dp[j] > mx) {
                    mx = dp[j];
                    mxc = cnt[j];
                }
                else if (dp[j] == mx) {
                    mxc = mxc.add(cnt[j]);
                }
            }
            dp[i] = mx+1;
            cnt[i] = mxc;
        }

        int mx = 0;
        BigInteger mxc = BigInteger.ONE;
        
        for (int j = n-1; j >= 0; j--) {
            if (next[j] < n) continue;
            if (dp[j] > mx) {
                mx = dp[j];
                mxc = cnt[j];
            }
            else if (dp[j] == mx) {
                mxc = mxc.add(cnt[j]);
            }
        }

        io.println(mx + " " + mxc);

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
