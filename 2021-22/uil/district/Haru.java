import java.util.*;
import java.io.*;

class Solution {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();

        int T = io.nextInt();

		int prev_p1y, prev_p1x, prev_p2y, prev_p2x;

		while (T-->0) {
			int[][] game = new int[100][100];
			int N = io.nextInt();
			int p1x, p1y, p2x, p2y;
			String p1instruct, p2instruct;
			p1x = io.nextInt();
			p1y = io.nextInt();
			p1instruct = io.next();
			p2x = io.nextInt();
			p2y = io.nextInt();
			p2instruct = io.next();

			game[p1y][p1x] = 1;
			game[p2y][p2x] = 2;

			boolean end = false;

			while (p1instruct.length() > 0) {

				if (end) break;

				prev_p1x= p1x;
				prev_p1y = p1y;
				prev_p2x = p2x;
				prev_p2y = p2y;

				game[p1y][p1x] = 3;

				if (p1instruct.charAt(0) == 'U') {
					p1y--;
				} else if (p1instruct.charAt(0) == 'D') {
					p1y++;
				} else if (p1instruct.charAt(0) == 'L') {
					p1x--;
				} else {
					p1x++;
				}

				game[p2y][p2x] = 3;

				if (p2instruct.charAt(0) == 'U') {
					p2y--;
				} else if (p2instruct.charAt(0) == 'D') {
					p2y++;
				} else if (p2instruct.charAt(0) == 'L') {
					p2x--;
				} else {
					p2x++;
				}

				System.out.println(p1x + " " + p1y + " " + p2x + " " + p2y);

				boolean p1dead = false;
				boolean p2dead = false;

				if (p1x < 0 || p1x >= 100 || p1y < 0 || p1y >= 100) {
					p1dead = true;
				} else if (game[p1y][p1x] == 3) {
					p1dead = true;
				}

				if (p2x < 0 || p2x >= 100 || p2y < 0 || p2y >= 100) {
					p2dead = true;
				} else if (game[p2y][p2x] == 3) {
					p2dead = true;
				}
				
				if (p1x == p2x && p1y == p2y || p1x == prev_p2x && p1y == prev_p2y || p2x == prev_p1x && p2y == prev_p1y) {
					end = true;
					System.out.println("HEAD ON");
					break;
				}

				if (p2dead && p1dead) {
					end = true;
					System.out.println("DOUBLE SPIKE");
				} else if (p1dead) {
					end = true;
					System.out.println("PLAYER 2 WINS");
				} else if (p2dead) {
					end = true;
					System.out.println("PLAYER 1 WINS");
				}

				p1instruct = p1instruct.substring(1);
				p2instruct = p2instruct.substring(1);

				if (!end){
					game[p1y][p1x] = 1;
					game[p2y][p2x] = 2;
				}
			}

			if (!end) {
				io.println("DRAW");
			}

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


/*
5
1
5 6 R
6 6 L
3
3 3 RRR
5 4 DDD
1
0 0 U
1 1 L
2
0 0 UR
1 1 DL
2
0 0 UU
1 1 UU
2
5 5 LR
10 10 RR
3
5 4 DDD
3 3 RRR
 */