
/*
struct UnionFind {
    vector<int> parent;
    int size;
    UnionFind(int n) :parent(n, -1), size(n) {}
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y)return false;
        if (sizeOf(x) < sizeOf(y))swap(x, y);
        parent[x] += parent[y]; parent[y] = x; size--;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
    int sizeOf(int x) { return -parent[root(x)]; }
};
*/

public class Solve {

    private class UnionFind {

        private int size;

        ArrayList<Integer> parent;

        UnionFind(int size) {
            this.size = size;
            parent = new ArrayList<Integer>(size);
            for (int i = 0; i < parent.length; i++) {
                parent.set(i, -1);
            }
        }

        boolean unite(int x, int y) {
            x = root(x); y = root(y);
            if (x == y) return false;
            if (sizeOf(x) < sizeOf(y)) {
                int tmp = x; x = y; y = tmp;
            }
            parent.set(x, parent.get(x) + parent.get(y));
            parent.set(y, parent.get(x));
            size--;
            return true;
        }
        
        boolean same(int x, int y) { 
            return root(x) == root(y);
        }

        int root(int x) {
            return (parent.get(x) < 0) ? 
                x : parent.set(x, root(parent.get(x)));
        }

        int sizeOf(int x) {
            return -parent[root(x)];
        }
    }

    public static void main(String[] args) {


    }
}


