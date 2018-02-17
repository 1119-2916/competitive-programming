import java.awt.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;

public class Judge {

    static class Output {
        ArrayList<Point> swapPos = new ArrayList<>();

        Output(Scanner sc) {
            while (sc.hasNext()) {
                int R = sc.nextInt();
                int C = sc.nextInt();
                swapPos.add(new Point(C, R));
            }
        }
    }

    static class Result {
        TestCase input;
        Output output;
        int finalCost;

        Result(TestCase input, Output output) {
            this.input = input;
            this.output = output;
        }

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder();
            int score = (Math.max(0, input.initialCost - finalCost) + 99) / 100;
            builder.append("score:" + score + "\n");
            builder.append("  initial cost:" + input.initialCost + "\n");
            builder.append("    final cost:" + finalCost + "\n");
            return builder.toString();
        }
    }

    static void validateOutput(TestCase testcase, Output output) {
        if (output.swapPos.size() % 2 != 0) {
            throw new RuntimeException("invalid output count");
        }
        if (output.swapPos.size() / 2 > testcase.K) {
            throw new RuntimeException("too many output");
        }
        for (int i = 0; i < output.swapPos.size(); ++i) {
            Point p = output.swapPos.get(i);
            if (p.x < 0 || testcase.W <= p.x || p.y < 0 || testcase.H <= p.y) {
                String message = String.format("invalid coordinate at row %d: (r=%d, c=%d)", i / 2 + 1, p.y, p.x);
                throw new RuntimeException(message);
            }
        }
    }

    static Result calcScore(TestCase testcase, Output output) {
        Result res = new Result(testcase, output);
        Point[][] finalPos = new Point[testcase.H][testcase.W];
        for (int i = 0; i < testcase.H; i++) {
            for (int j = 0; j < testcase.W; j++) {
                finalPos[i][j] = new Point(j, i);
            }
        }
        for (int i = output.swapPos.size() / 2 - 1; i >= 0; i--) {
            Point p1 = output.swapPos.get(i * 2);
            Point p2 = output.swapPos.get(i * 2 + 1);
            Point tmp = finalPos[p1.y][p1.x];
            finalPos[p1.y][p1.x] = finalPos[p2.y][p2.x];
            finalPos[p2.y][p2.x] = tmp;
        }
        for (int i = 0; i < testcase.D - 1; i++) {
            Point prev = testcase.sectors[i];
            Point next = testcase.sectors[i + 1];
            prev = finalPos[prev.y][prev.x];
            next = finalPos[next.y][next.x];
            res.finalCost += Math.abs(next.x - prev.x) + Math.abs(next.y - prev.y);
        }
        return res;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
            System.err.println("usage: java Judge input_file_path output_file_path");
            System.exit(1);
        }
        Path inputFile = Paths.get(args[0]);
        Path outputFile = Paths.get(args[1]);
        TestCase testcase = new TestCase(new Scanner(inputFile));
        Output output = new Output(new Scanner(outputFile));
        validateOutput(testcase, output);
        Result res = calcScore(testcase, output);
        System.out.print(res);
    }

}
