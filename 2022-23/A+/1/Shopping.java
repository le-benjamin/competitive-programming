import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Shopping {
    public static class Pair {
        public int r, c;
        public Pair(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static boolean bfs(char[][] g, Pair s, Pair end) {
        Queue<Pair> q = new LinkedList<>();
        boolean[][] vis = new boolean[g.length][g[0].length];
        q.add(s);
        vis[s.r][s.c] = true;
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            for (int i = 0; i < 4; i++) {
                try {
                    Pair next = new Pair(cur.r+dx[i], cur.c+dy[i]);
                    if (g[next.r][next.c] == g[end.r][end.c]) return true;
                    else if (!vis[next.r][next.c] && g[next.r][next.c] == '.') q.add(next);
                    vis[next.r][next.c] = true;
                } catch (Exception e) {}
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt(); in.nextLine();
        while (tc-->0) {
            List<Integer> list = Arrays.stream(in.nextLine().split(",")).map(Integer::valueOf).collect(Collectors.toList());
            int r = list.get(0), c = list.get(1), i = list.get(2);
            Map<Character, Pair> hm = new HashMap<>();
            Pair prev = new Pair(0, 0);
            char[][] g = new char[r][c];
            for (int j = 0; j < r; j++) {
                g[j] = in.nextLine().toCharArray();
                for (int k = 0; k < c; k++) {
                    if ((""+g[j][k]).toLowerCase().matches("[a-z]")) hm.put(g[j][k], new Pair(j, k));
                    if (g[j][k] == 'e') prev = new Pair(j, k);
                }
            }

            boolean good = true;

            for (int j = 0; j < i; j++) {
                Pair cur = hm.get(in.nextLine().charAt(0));
                if (good && !bfs(g, prev, cur)) good = false;
                try{
                    g[prev.r][prev.c] = '.';
                } catch (Exception e) {}
                prev = cur;
            }

            out.println(good ? "It's grocery time!" : "It's not grocery time, sorry champ.");
        }
    }
}