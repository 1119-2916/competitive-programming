import java.awt.*;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Scanner;

public class TestCase {

    private static final int W_FIXED = 200;
    private static final int H_FIXED = 200;
    private static final int D_FIXED = 16000;
    private static final int K_FIXED = 4000;

    int W, H, K, D;
    Point[] sectors;
    int initialCost;
    SecureRandom rnd;

    TestCase(long seed) throws Exception {
        rnd = SecureRandom.getInstance("SHA1PRNG");
        rnd.setSeed(seed);
        this.H = H_FIXED;
        this.W = W_FIXED;
        this.D = D_FIXED;
        this.K = K_FIXED;
        this.sectors = new Point[D];
        ArrayList<Point> allPoints = new ArrayList<>(H * W);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                allPoints.add(new Point(j, i));
            }
        }
        for (int i = 0; i < D; i++) {
            int pos = rnd.nextInt(allPoints.size() - i) + i;
            sectors[i] = allPoints.get(pos);
            allPoints.set(pos, allPoints.get(i));
        }
        calcInitialCost();
    }

    TestCase(Scanner sc) {
        this.H = sc.nextInt();
        this.W = sc.nextInt();
        this.D = sc.nextInt();
        this.K = sc.nextInt();
        this.sectors = new Point[D];
        for (int i = 0; i < D; i++) {
            int Y = sc.nextInt();
            int X = sc.nextInt();
            sectors[i] = new Point(X, Y);
        }
        calcInitialCost();
    }

    void calcInitialCost() {
        initialCost = 0;
        for (int i = 0; i < D - 1; i++) {
            Point prev = sectors[i];
            Point next = sectors[i + 1];
            initialCost += Math.abs(next.x - prev.x) + Math.abs(next.y - prev.y);
        }
    }

    private int getRandomInt(int minInclusive, int maxInclusive) {
        return rnd.nextInt(maxInclusive - minInclusive + 1) + minInclusive;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append(this.H + " " + this.W + " " + this.D + " " + this.K + "\n");
        for (int i = 0; i < D; i++) {
            builder.append(sectors[i].y + " " + sectors[i].x + "\n");
        }
        return builder.toString();
    }


}
