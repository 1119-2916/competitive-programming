#define UF uftree
#define MAX_UF 101000

class uftree 
{
    public:
        int size;
        vector<int> par, rank;
        uftree(int n) : size(n), par(n), rank(n) {
            for (int i = 0; i < size; i++) {
                par[i] =  i;
                rank[i] = 0;
            }
        }
        int find(int x) {
            if (par[x] == x) {
                return x;
            } else {
                return par[x] = find(par[x]);
            }
        }
        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return ;
            }

            if (rank[x] < rank[y]) {
                par[x] = y;
            } else {
                par[y] = x;
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }
        bool same(int x, int y) {
            return find(x) == find(y);
        }
};
