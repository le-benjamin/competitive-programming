import java.util.*;

public class Wade {
    public static class Pair {
        public int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int tc = in.nextInt();
        in.nextLine();
        while (tc --> 0) {
            
            Pair knight = null;
            Pair queen = null;

            for (int y = 0; y < 8; y++) {
                String line = in.nextLine();
                if (line.contains("K")) {
                    knight = new Pair(line.indexOf("K"), y);
                }
                if (line.contains("Q")) {
                    queen = new Pair(line.indexOf("Q"), y);
                }
            }   

            System.out.println(knight + " " + queen);

            int[] movesX = {1, 1, -1, -1, 2, 2, -2, -2};
            int[] movesY = {2, -2, 2, -2, 1, -1, 1, -1};

            Queue<Pair> Q = new LinkedList<>();
            Q.add(knight);

            int[][] dist = new int[8][8];

            while (Q.size() > 0) {
                Pair p = Q.poll();

                for (int i = 0; i < 8; i++) {
                    int x = p.x + movesX[i];
                    int y = p.y + movesY[i];

                    if (x >= 0 && x < 8 && y >= 0 && y < 8 && dist[x][y] == 0) {
                        dist[x][y] = dist[p.x][p.y] + 1;
                        Q.add(new Pair(x, y));
                    }
                }
            }

            System.out.println(dist[queen.x][queen.y]);

        }

    }
}