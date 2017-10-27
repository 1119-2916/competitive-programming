import java.util.*;

class Main {

    static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {

        while (scan.hasNext()) {
            int n = scan.nextInt();
            int money = scan.nextInt();
            boolean[] dp = new boolean[money+1];
            if (n == 0) {
                break;
            }
            int[] menu = new int[30];
            for (int i = 0; i < n; i++) {
                menu[i] = scan.nextInt();
            }
            solve(dp, menu);
            int i;
            for (i = dp.length-1; i >= 0; i--) {
                if (dp[i] && prime(i)) {
                    break;
                }
            }
            if (i < 0) {
                System.out.println("NA");
            } else {
                System.out.println(i);
            }
        }
    }

    public static void solve(boolean dp[], int menu[]) {
        for (int i = 0; i < menu.length; i++) {
            if (menu[i] > dp.length) {
                continue;
            }
            dp[menu[i]] = true;
            for (int j = 1; j < dp.length; j++) {
                if (dp[j] && j + menu[i] < dp.length) {
                    dp[j+menu[i]] = true;
                }
            }
        }
    }



    public static boolean prime(int a) {
        if (a <= 3) {
            return true;
        } else {
            for (int i = 2; i * i <= a; i++) {
                if (a % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }
}
                    
