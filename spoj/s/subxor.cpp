#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd


/*
 * 正整数値の入力を想定
 * xor した i 番目を取り出したい時は xor(x) get(i) xor(x) する
 */
template< int dig = 64 >
struct Binary_Trie {
    using T = int; // int 以外の利用を想定していない 定数のキャストのため
    bool use_set = false;
    struct Trie_Node {
        struct Trie_Node *left, *right;
        std::set< int > ids; // 自分以下の id のリスト
        int num;
        T lazy;
        Trie_Node() : left(nullptr), right(nullptr), num(0), lazy(0) {}
        Trie_Node(Trie_Node *left, Trie_Node *right) : left(left), right(right) 
        {
            this->num = 0; this->lazy = 0;
            if (left != nullptr) this->num += left->num; 
            if (right != nullptr) this->num += right->num; 
        }
    };
    Trie_Node *head;
    Binary_Trie() : head(nullptr) {}
    int size() { return (head) ? head->num : 0; }
    bool empty() { return !head; }
    void propagate(Trie_Node *p, int digit) {
        if ((p->lazy >> (T)digit) & (T)1) swap(p->left, p->right);
        if (p->left) p->left->lazy ^= p->lazy;
        if (p->right) p->right->lazy ^= p->lazy;
        p->lazy = 0;
    }
    Trie_Node* add(Trie_Node *p, int input, int id, int digit = dig-1) {
        if (!p) p = new Trie_Node;
        p->num++; 
        if (use_set) p->ids.insert(id);
        if (digit < 0) return p;
        propagate(p, digit);
        bool f = (input >> (T)digit) & (T)1;
        if (f) p->right = add(p->right, input, id, digit-1);
        else p->left = add(p->left, input, id, digit-1);
        return p;
    }
    Trie_Node* remove(Trie_Node *p, int input, int id, int digit = dig-1) {
        if (p->num == 1) return nullptr;
        p->num--; 
        if (use_set) p->ids.erase(id);
        if (digit < 0) return p;
        propagate(p, digit);
        bool f = (input >> (T)digit) & (T)1;
        if (f) p->right = remove(p->right, input, id, digit-1);
        else p->left = remove(p->left, input, id, digit-1);
        return p;
    }
    // k 番目に小さい値を得る [0, n)
    // 0-index なので注意
    T get(Trie_Node *p, int k, int digit = dig-1) {
        if (digit < 0) return 0;
        propagate(p, digit);
        int tmp = p->left ? p->left->num : 0;
        return ((k < tmp) ?  get(p->left, k, digit-1) : 
            (get(p->right, k-tmp, digit-1) | ((T)1 << (T)digit)));
    }
    // 数 k よりも小さい値の中で最大のものがいくつあるか
    // k bit ある時、2^k-1 は利用できないことに注意
    int search(Trie_Node *p, int k, int digit = dig-1) {
        if (!p || digit < 0) return 0;
        propagate(p, digit);
        int f = (k >> (T)digit) & (T)1;
        if (f) return search(p->right, k, digit-1)
            + (p->left ? p->left->num : 0);
        else return search(p->left, k, digit-1);
    }

    void insert(int input, int id = 0) {
        head = add(head, input, id);
    }
    void eject(int input, int id = 0) {
        head = remove(head, input, id);
    }
    T query(int k) {
        return get(head, k);
    }
    void xor_all(int x) {
        if (head) head->lazy ^= x;
    }
    // data 以上で最小の値が何番目か
    int lower_bound(int data) {
        return search(head, data);
    }
#ifdef DEBUG
    void trace() {
        deque<Trie_Node *> que;
        que.emplace_back(head);
        while (!que.empty()) {
            deque<Trie_Node *> nxt;
            while (!que.empty()) {
                cout << que.front()->num << " : ";
                if (que.front()->left) {
                    cout << 0 << " ";
                    nxt.emplace_back(que.front()->left);
                }
                if (que.front()->right) {
                    cout << 1 << " ";
                    nxt.emplace_back(que.front()->right);
                }
                cout << endl;
                que.pop_front();
            }
            que = nxt;
        }
    }
#endif
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(t);
    while (t--) {
        int2(n, k);
        vector<int> data(n);
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }
        
        Binary_Trie<> funami;
        int yui = 0;
        rep(i, data.size()) {
            yui ^= data[i];
            funami.insert(yui);
        }

        yui = 0;
        int kyoko = 0;
        int ans = 0;
        rep(i, data.size()) {
            funami.xor_all(yui);
            ans += funami.lower_bound(k);
            //cout << funami.lower_bound(k) << " ";
            funami.xor_all(yui);
            kyoko ^= data[i];
            funami.eject(kyoko);
            yui ^= data[i];
        }
        cout << ans << endl;
    }

    return 0;
}
