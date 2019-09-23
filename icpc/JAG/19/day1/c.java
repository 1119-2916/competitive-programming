import java.util.*;
import java.io.*;

public class c {
    public static void main(String[] args) {
        Scanner ir = new Scanner(System.in);
        int n = ir.nextInt();
        long l = ir.nextLong();
        long[][] x = new long[n][];
        for (int i = 0; i < n; i++) {
            x[i] = new long[] { ir.nextLong(), ir.nextLong() };
        }
        int[][] a = compress(x);
        // System.out.println(Arrays.deepToString(a));
        Arrays.sort(a, new Comparator<int[]>() {
            public int compare(int[] A, int[] B) {
                return A[0] - B[0];
            }
        });
        int ma = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                ma = Math.max(ma, a[i][j]);
            }
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int end = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (end == ma) {
                break;
            }
            while (i < n && a[i][0] <= end) {
                pq.add(a[i][1]);
                i++;
            }
            i--;
            end = pq.poll();
            // System.out.println(end);
            res++;
        }
        System.out.print(res + " ");
        int[] imos = new int[ma + 1];
        for (int i = 0; i < n; i++) {
            imos[a[i][0]]++;
            imos[a[i][1]]--;
        }
        res = imos[0];
        for (int i = 0; i < ma; i++) {
            imos[i + 1] += imos[i];
            res = Math.min(res, imos[i]);
        }
        System.out.println(n + 1 - res);
    }

    static int[][] compress(long[][] a) {
        int[][] ret = new int[a.length][2];
        TreeSet<Long> st = new TreeSet<>();
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < 2; j++) {
                st.add(a[i][j]);
            }
        }
        ArrayList<Long> l = new ArrayList<>(st);
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < 2; j++) {
                ret[i][j] = Collections.binarySearch(l, a[i][j]);
            }
        }
        return ret;
    }
}