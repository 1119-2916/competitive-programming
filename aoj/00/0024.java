import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int w = scan.nextInt();
        int data = 1;
        while (w != 0) {
            int n = scan.nextInt();
            int[] value = new int[n];
            int[] weight = new int[n];
            for (int i = 0; i < n; i++) {
                String[] str = scan.next().split(",");
                value[i] = Integer.parseInt(str[0]);
                weight[i] = Integer.parseInt(str[1]);;
            }
            int[] dp = new int[w+1];
            for (int i = 0; i < n; i++) {
                for (int j = w; j >= 0; j--) {
                    if ((dp[j] != 0 && (j + weight[i]) <= w)
                            || (j == 0)) {
                        dp[j + weight[i]] = 
                            max(dp[j + weight[i]], dp[j] + value[i]);
                            }
                }
            }
            int max = 0;
            for (int i = 0; i <= w; i++) {
                if (dp[i] > dp[max]) {
                    max = i;
                }
            }
            System.out.println("Case " + data + ":");
            System.out.println(dp[max]);
            System.out.println(max);
            data++;
            w = scan.nextInt();
        }
    }

    public static int max(int a, int b) {
        if (a < b) {
            return b;
        } else {
            return a;
        }
    }
}


