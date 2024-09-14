import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Marching {
    public static class Node {
        int r, c, n;

        public Node(int r, int c, int n) {
            this.r = r;
            this.c = c;
            this.n = n;
        }
    }
    
    public static int bfs(char[][] g, Node s) {
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        boolean[][] vis = new boolean[g.length][g[0].length];
        Queue<Node> q = new LinkedList<>();
        q.add(s);
        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; i++) {
                try {
                    Node next = new Node(cur.r+dx[i], cur.c+dy[i], cur.n+1);
                    if ((""+g[next.r][next.c]).equals((""+g[s.r][s.c]).toLowerCase())) return next.n;
                    if (g[next.r][next.c] != '#' && !vis[next.r][next.c]) q.add(next);
                    vis[next.r][next.c] = true;
                } catch (Exception e) {}
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int n = in.nextInt(), m = in.nextInt();
            Map<String, Node> hm = new HashMap<>();
            char[][] g = new char[n][m];
            for (int i = 0; i < n; i++) {
                g[i] = in.next().toCharArray();
                for (int j = 0; j < m; j++) { 
                    if (g[i][j] >= 'A' && g[i][j] <= 'Z') hm.put(""+g[i][j], new Node(i, j, 0));
                }
            }
            int ret = 0;
            for (var entry : hm.entrySet()) ret += bfs(g, entry.getValue());
            out.println(ret);
        }
    }
}