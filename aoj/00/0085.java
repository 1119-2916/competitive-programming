
import java.util.*;

class Main {

    public static void main(String[] args) {
        Deque<Integer> stack = new ArrayDeque<Integer>();
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        while (n != 0) {
            for (int i = 0; i < n; i++) {
                stack.addLast(i+1);
            }
            int ans = 0;
            while (stack.peekFirst() != null) {
                for (int i = 0; i < m-1; i++) {
                    int tmp = stack.pollFirst();
                    stack.addLast(tmp);
                }
                ans = stack.pollFirst();
            }
            System.out.println(ans);
            n = scan.nextInt();
            m = scan.nextInt();
        }
    }
}


