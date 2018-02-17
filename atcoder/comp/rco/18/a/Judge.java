
import java.awt.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class Judge {

    static final int[] DR = {-1, 0, 1, 0};
    static final int[] DC = {0, 1, 0, -1};
    static final String DIR = "URDL";

    static class Output {
        int[] fieldIds;
        String commands;

        Output(int K, Scanner sc) {
            String[] fields = sc.nextLine().trim().split(" ");
            if (fields.length != K) {
                throw new RuntimeException("number of fields is not equal to K");
            }
            this.fieldIds = new int[K];
            for (int i = 0; i < K; i++) {
                try {
                    this.fieldIds[i] = Integer.parseInt(fields[i]);
                } catch (NumberFormatException e) {
                    throw new RuntimeException("field No. is not an interger:" + fields[i]);
                }
            }
            if (sc.hasNext()) {
                this.commands = sc.next();
            } else {
                this.commands = "";
            }
        }
    }

    static class Result {
        TestCase input;
        Output output;
        int[] fieldScores;
        int score;

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder();
            builder.append("score:" + score + "\n");
            for (int i = 0; i < input.K; i++) {
                builder.append(String.format("  field No.%2d:%4d\n", output.fieldIds[i], fieldScores[i]));
            }
            return builder.toString();
        }
    }

    static void validateOutput(TestCase testcase, Output output) {
        boolean[] used = new boolean[testcase.N];
        for (int i = 0; i < testcase.K; i++) {
            int f = output.fieldIds[i];
            if (used[f]) {
                throw new RuntimeException("field No." + f + " is already used.");
            }
            used[f] = true;
        }
        if (output.commands.length() > testcase.T) {
            throw new RuntimeException("commands length is larger than T.");
        }
        for (int j = 0; j < output.commands.length(); j++) {
            if (DIR.indexOf(output.commands.charAt(j)) < 0) {
                throw new RuntimeException("invalid command at index " + j + ":" + output.commands.charAt(j));
            }
        }
    }

    static Result calcScore(TestCase testcase, Output output) {
        Result res = new Result();
        res.input = testcase;
        res.output = output;
        res.fieldScores = new int[testcase.K];
        int[] pr = new int[testcase.K];
        int[] pc = new int[testcase.K];
        boolean[] captured = new boolean[testcase.K];
        for (int i = 0; i < testcase.K; i++) {
            char[][] field = testcase.fields[output.fieldIds[i]];
            Point pos = findPlayerPosition(field);
            pr[i] = pos.y;
            pc[i] = pos.x;
        }
        for (int i = 0; i < output.commands.length(); i++) {
            int dir = DIR.indexOf(output.commands.charAt(i));
            for (int j = 0; j < testcase.K; j++) {
                char[][] field = testcase.fields[output.fieldIds[j]];
                if (captured[j]) continue;
                int nr = pr[j] + DR[dir];
                int nc = pc[j] + DC[dir];
                if (field[nr][nc] == TestCase.WALL) continue;
                if (field[nr][nc] == TestCase.TRAP) {
                    captured[j] = true;
                    continue;
                }
                if (field[nr][nc] == TestCase.COIN) {
                    ++res.fieldScores[j];
                }
                field[pr[j]][pc[j]] = TestCase.EMPTY;
                pr[j] = nr;
                pc[j] = nc;
            }
        }
        for (int i = 0; i < testcase.K; i++) {
            res.score += res.fieldScores[i];
        }
        return res;
    }

    private static Point findPlayerPosition(char[][] field) {
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[i].length; j++) {
                if (field[i][j] == TestCase.PLAYER) {
                    return new Point(j, i);
                }
            }
        }
        return null;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
            System.err.println("usage: java Judge input_file_path output_file_path");
            System.exit(1);
        }
        Path inputFile = Paths.get(args[0]);
        Path outputFile = Paths.get(args[1]);
        TestCase testcase = new TestCase(new Scanner(inputFile));
        Output output = new Output(testcase.K, new Scanner(outputFile));
        validateOutput(testcase, output);
        Result res = calcScore(testcase, output);
        System.out.print(res);
    }

}
