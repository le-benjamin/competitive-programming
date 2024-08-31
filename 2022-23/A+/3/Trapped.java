import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Trapped {
    public static class Node {
        public int r, c;
        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static boolean bfs(char[][] g, Node s) {
        Queue<Node> q = new LinkedList<>();
        boolean[][] vis = new boolean[g.length][g.length];
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        q.add(s);
        vis[s.r][s.c] = true;
        while (!q.isEmpty()) {
            Node cur = q.poll();
            if (cur.r == 0 || cur.c == 0 || cur.r == g.length-1 || cur.c == g.length-1) return true;
            for (int i = 0; i < 4; i++) {
                Node next = new Node(cur.r+dx[i], cur.c+dy[i]);
                if (!vis[next.r][next.c] && g[next.r][next.c] != '*') q.add(next);
                vis[next.r][next.c] = true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int x = in.nextInt();
            char[][] g = new char[x][x];
            Node s = new Node(0, 0);
            for (int i = 0; i < x; i++) {
                g[i] = in.next().toCharArray();
                for (int j = 0; j < x; j++) {
                    if (g[i][j] == '@') s = new Node(i, j);
                }
            }

            out.println(bfs(g, s) ? "Exit" : "No Exit");
        }
    }
}