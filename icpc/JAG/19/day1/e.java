import java.util.*;
import java.io.*;

public class c {
    public static void main(String[] args) {
        Scanner ir = new Scanner(System.in);
        int n = ir.nextInt();
        int m = ir.nextInt();
        Graph[] g = new Graph[n];
        for (int i = 0; i < n; i++) {
            g[i] = new Graph();
        }

    }

    static class Graph extends ArrayList<int[]> {
    }
}