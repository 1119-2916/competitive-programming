
import java.security.SecureRandom;
import java.util.Scanner;

public class TestCase {

    static final int MIN_SIZE = 50;
    static final int MAX_SIZE = 50;
    static final int MIN_N = 100;
    static final int MAX_N = 100;
    static final int MIN_K = 8;
    static final int MAX_K = 8;
    static final int MIN_T = MAX_SIZE * MAX_SIZE;
    static final int MAX_T = MAX_SIZE * MAX_SIZE;
    static final double MIN_PROB_WALL = 0.20;
    static final double MAX_PROB_WALL = 0.20;
    static final double MIN_PROB_TRAP = 0.03;
    static final double MAX_PROB_TRAP = 0.03;
    static final char PLAYER = '@';
    static final char COIN = 'o';
    static final char TRAP = 'x';
    static final char WALL = '#';
    static final char EMPTY = '_';

    int N, K, H, W, T;
    char[][][] fields;
    SecureRandom rnd;

    TestCase(long seed) throws Exception {
        rnd = SecureRandom.getInstance("SHA1PRNG");
        rnd.setSeed(seed);
        this.N = getRandomInt(MIN_N, MAX_N);
        this.K = getRandomInt(MIN_K, MAX_K);
        this.H = getRandomInt(MIN_SIZE, MAX_SIZE);
        this.W = getRandomInt(MIN_SIZE, MAX_SIZE);
        this.T = getRandomInt(MIN_T, MAX_T);
        this.fields = new char[N][H][W];
        for (int i = 0; i < N; i++) {
            double probWall = getRandomDouble(MIN_PROB_WALL, MAX_PROB_WALL);
            double probTrap = getRandomDouble(MIN_PROB_TRAP, MAX_PROB_TRAP);
            for (int j = 0; j < H; j++) {
                this.fields[i][j][0] = this.fields[i][j][W - 1] = WALL;
            }
            for (int j = 0; j < W; j++) {
                this.fields[i][0][j] = this.fields[i][H - 1][j] = WALL;
            }
            for (int j = 1; j < H - 1; j++) {
                for (int k = 1; k < W - 1; k++) {
                    double v = rnd.nextDouble();
                    if (v < probWall) {
                        this.fields[i][j][k] = WALL;
                    } else if (v < probWall + probTrap) {
                        this.fields[i][j][k] = TRAP;
                    } else {
                        this.fields[i][j][k] = COIN;
                    }
                }
            }
            int PH = rnd.nextInt(H - 2) + 1;
            int PW = rnd.nextInt(W - 2) + 1;
            this.fields[i][PH][PW] = PLAYER;
        }
    }

    TestCase(Scanner sc) {
        this.N = sc.nextInt();
        this.K = sc.nextInt();
        this.H = sc.nextInt();
        this.W = sc.nextInt();
        this.T = sc.nextInt();
        this.fields = new char[N][H][];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < H; j++) {
                this.fields[i][j] = sc.next().toCharArray();
            }
        }
    }

    private int getRandomInt(int minInclusive, int maxInclusive) {
        return rnd.nextInt(maxInclusive - minInclusive + 1) + minInclusive;
    }

    private double getRandomDouble(double minInclusive, double maxInclusive) {
        return rnd.nextDouble() * (maxInclusive - minInclusive) + minInclusive;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append(this.N + " " + this.K + " " + this.H + " " + this.W + " " + this.T + "\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < H; j++) {
                builder.append(String.valueOf(this.fields[i][j]) + "\n");
            }
        }
        return builder.toString();
    }

}
