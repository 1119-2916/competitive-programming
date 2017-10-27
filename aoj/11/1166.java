import java.util.*;

class Main {
    public static Queue<Integer> nowX = new ArrayDeque<Integer>();
    public static Queue<Integer> nowY = new ArrayDeque<Integer>();
    public static Scanner scan = new Scanner(System.in);
    public static int m, n;

    public static void main(String[] args) {
        n = scan.nextInt();
        m = scan.nextInt();
        while (n != 0 && m != 0) {
            boolean[][] board = new boolean[m+m][n+n];
            makeboard(board);
            boolean flag = false;
            int count = 0;
            while (nowX.poll() != null) {
                nowY.poll();
            }
            nowX.add(0);
            nowY.add(0);
            int frame = 0;
            while (!flag) {
                if (nowX.peek() == null) {
                    count = 0;
                    break;
                }
                flag = bfs(board);
                count++;
            }
            System.out.println(count);
            n = scan.nextInt();
            m = scan.nextInt();
        }
    }

    public static boolean bfs(boolean board[][]) {
        Queue<Integer> nextX = new ArrayDeque<Integer>();
        Queue<Integer> nextY = new ArrayDeque<Integer>();
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
        while (nowX.peek() != null) {
            int x = nowX.poll();
            int y = nowY.poll();
            board[x][y] = false;
            if (x == m+m-2 && y == n+n-2) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                if (over(x+dx[i], m) && over(y+dy[i], n) && 
                        over(x+dx[i]+dx[i], m) && over(y+dy[i]+dy[i], n)) {
                    if (board[x+dx[i]][y+dy[i]]) {
                        board[x+dx[i]][y+dy[i]] = false;
                        nextX.add(x+dx[i]+dx[i]);
                        nextY.add(y+dy[i]+dy[i]);
                    }
                        }
            }
        }
        nowX = nextX;
        nowY = nextY;
        return false;
    }

    public static boolean over(int a, int f) {
        if (a < 0) {
            return false;
        } else if (f+f-2 < a) {
            return false;
        } else {
            return true;
        }
    }

    public static void makeboard(boolean board[][]) {
        for (int i = 0 ; i < m+m; i++) {
            for (int j = 0; j < n+n; j++) {
                board[i][j] = true;
            }
        }
        for (int i = 0; i < m+m-1; i++) {
            for (int j = 0; j < n+n-1; j++) {
                if (i % 2 == 0) {
                    j++;
                    if (j >= n+n-1) {
                        continue;
                    }
                    if (scan.nextInt() == 1) {
                        board[i][j] = false;
                    }
                } else {
                    if (scan.nextInt() == 1) {
                        board[i][j] = false;
                    }
                    j++;
                    if (j >= n+n-1) {
                        continue;
                    }
                }
            }
        }
    }

    public static void printboard(boolean board[][]) {
        for (int i = 0 ; i < m+m-1; i++) {
            for (int j = 0; j < n+n-1; j++) {
                if (board[i][j]) {
                    System.out.print("0");
                } else {
                    System.out.print("1");
                }
            }
            System.out.println("");
        }
    }
}
