import java.util.*;

class Main {
    static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scan.nextInt();
        int m = scan.nextInt();
        int[] dist = new int[n];
        int[] weather = new int[m];
        int[][] dp = new int[n+1][m+1];
        for (int i = 0; i < n; i++) {
            dist[i] = scan.nextInt();
        }
        for (int i = 0; i < m; i++) {
            weather[i] = scan.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = 2100000000;
            }
        }
        solve(dist, weather, dp);
        int min = 2100000000;
        for (int i = 0; i <= m; i++) {
            if (min > dp[n][i]) {
                min = dp[n][i];
            }
        }
        System.out.println(min);
        /*
        for (int i = 0; i < n+1; i++) {
            for (int j = 0; j < m+1; j++) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println(" ");
        }
        */
    }

    public static void solve(int dist[], int weather[], int dp[][]) {
        for (int i = 1; i <= dist.length; i++) {
            for (int j = i; j <= weather.length - dist.length + i; j++) {
                for (int k = i-1; k < j; k++) {
                    dp[i][j] = 
                        min(dp[i][j], dp[i-1][k]+(dist[i-1]*weather[j-1]));
                }
            }
        }
    }

    public static int min(int a, int b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }
}

