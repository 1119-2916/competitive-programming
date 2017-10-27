import java.lang.*;
import java.util.*;

class Main {

    public static double p;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        p = scan.nextDouble();
        System.out.println(p);
        System.out.println(search(0, 1000000000, 0));
    }

    public static double search(double start, double end, int count) {
        double ans;
        double left = (start + end) / 3;
        double right = (start + end) / 3 * 2;
        double aLeft = left + (Math.pow(2.0, left/1.5) * p);
        double aRight= right + (Math.pow(2.0, right/1.5) * p);
        if (aLeft - aRight < 0.00000001 && aLeft - aRight > -0.00000001) {
            if (aLeft < aRight) {
                return aLeft;
            } else {
                return aRight;
            }
        }
        if (aLeft < aRight) {
            ans = search(start, right, count+1);
        } else {
            ans = search(left, end, count+1);
        }
        return ans;
    }
}



