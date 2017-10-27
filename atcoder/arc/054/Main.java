import java.lang.*;
import java.util.*;

class Main {

    public static double p;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        p = scan.nextDouble();
        System.out.println(search(0, 25));
    }

    public static double search(double start, double end) {
        double ans;
        double left = (start + end) / 3;
        double right = (start + end) / 3 * 2;
        double aLeft = left + (p / Math.pow(2.0, left/1.5));
        double aRight= right + (p / Math.pow(2.0, right/1.5));
        if (aLeft - aRight < 0.00000001 && aLeft - aRight > -0.00000001) {
            if (aLeft < aRight) {
                return aLeft;
            } else {
                return aRight;
            }
        }
        if (aLeft < aRight) {
            System.out.println(aLeft);
            ans = search(start, right);
        } else {
            System.out.println(aRight);
            ans = search(left, end);
        }
        return ans;
    }
}



