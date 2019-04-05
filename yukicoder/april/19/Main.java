import java.util.*;

public class Main {
    public static void main(String args[]) {
        Random rnd = new Random();
        int k = rnd.nextInt(100);
        if (k < 80) {
            System.out.println("Yes");
        }
    }
}

