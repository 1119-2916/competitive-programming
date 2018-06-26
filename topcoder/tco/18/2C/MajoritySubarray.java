import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class MajoritySubarray {

    public long getCount(int n, int seed, int m) {
        long startTime = System.currentTimeMillis();
        int[] a = new int[n];
        long s = seed;
        for (int i = 0; i < n; i++) {
            a[i] = (int)((s >> 16) % m);
            s = (s * 1103515245 + 12345) % (1L << 31);
        }
        long ans = 0;
        if (m == 1) {
            ans = (long) n * (n + 1) / 2;
        } else if (m == 2) {
            int[] count = new int[n * 2 + 1];
            int now = n;
            count[now] = 1;
            for (int i = 0; i < n; i++) {
                now += a[i] == 1 ? 1 : -1;
                ans += now;
                count[now]++;
            }
        } else {
            ans = n;
            for (int len = 2; len <= n; len++) {
                if (System.currentTimeMillis() - startTime > 1600) break;
                int[] hist = new int[m];
                for (int i = 0; i <len; i++) {
                    hist[a[i]]++;
                }
                int max = getMax(hist);
                for (int i = len; ; i++) {
                    if (max > len / 2) ++ans;
                    if (i == n) break;
                    hist[a[i - len]]--;
                    if (hist[a[i - len]] == max - 1) {
                        max = getMax(hist);
                    }
                    hist[a[i]]++;
                    max = Math.max(max, hist[a[i]]);
                }
            }
        }
        return ans;
    }

    static int getMax(int[] h) {
        int m = 0;
        for (int i = 0; i < h.length; i++) {
            m = Math.max(m, h[i]);
        }
        return m;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        MajoritySubarray hoge = new MajoritySubarray();
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        System.out.println(hoge.getCount(a, b, c));
    }
}

