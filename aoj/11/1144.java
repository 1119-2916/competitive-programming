import java.util.*;

class Main{
    Deque now = new Deque<Integer>();
    Deque next = new Deque<Integer>();
    int[][] board = new int[20][20];
    int n, m;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        n = scan.nextInt();
        m = scan.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = scan.nextInt();
                if (board[i][j] == 2) {
                    stx = i;
                    sty = j;
                }
                if (board[i][j] == 3) {
                    glx = i;
                    gly = j;
                }
            }
        }
        while (





