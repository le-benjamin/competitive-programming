import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Run {
    public static class Node {
        public int node, depth;
        public Node(int node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }

    public static int bfs(boolean[][] g) {
        Queue<Node> q = new LinkedList<>();
        boolean[] vis = new boolean[g.length];
        vis[0] = true;
        q.add(new Node(0, 0));
        while (!q.isEmpty()) {
            Node cur = q.poll();
            if (cur.node == g.length-1) return cur.depth;
            for (int i = 1; i < g.length; i++) {
                if (!vis[i] && g[cur.node][i]) {
                    q.add(new Node(i, cur.depth+1));
                    vis[i] = true;
                }
            }
        }

        return 999999999;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        while (tc-->0) {
            int l = in.nextInt(), x = in.nextInt(); in.nextLine();
            boolean[][] g = new boolean[x][x];
            for (int i = 0; i < x; i++) {
                String[] line = in.nextLine().split(" ");
                for (int j = 0; j < x; j++) g[i][j] = line[j].equals("1");
            }
            out.println(bfs(g) < l ? "Safe at last." : "This is the end of me!");
        }
    }
}