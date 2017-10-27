#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1010001000

using namespace std;

int n, k;

typedef struct tree {
    int value;
    bool check;
    vector<int> neighbor;
}Tree;

Tree tree[100001];

int main()
{
    cin >> n;
    int a, b;

    tree[0].value = INF;
    tree[0].check = false;
    for (i = 1; i < n; i++) {
        tree[i].value = INF;
        tree[i].check = false;
        cin >> a >> b;
        tree[a].neighbor.push_back(b);
        tree[b].neighbor.push_back(a);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        tree[a].value = b;
    }

    if (dfs(a)) {
        cout << Yes << endl;
    } else {
        cout << No << endl;
    }

    return 0;

}

bool dfs(int st)
{
    tree[st].check = true;
    for (int i = 0; i < tree[st].neighbor.size(); i++) {
        if (!dfs_ans(tree[st].neighbor[i], tree[st].value, 1)) {
            return false;
        }
    }
}

bool dfs_ans(int pos, int val, int dep)
{
    if (!tree[pos].check) {
        tree[pos].check = true;
    } else {
        return true;
    }
    if (tree[pos].value == INF) {
        for (int i = 0; i < tree[pos].neighbor.size(); i++) {
            dfs_ans(i, val, dep+1);
        }
    } else {
        if (dep % 2) {
            if ((tree[pos].value % 2) == (val % 2)) {
                return false;
            } else {
                if (tree[pos].value < val) {
                    if (val - dep > tree[pos].value) {
                        return false;
                    }
                } else {
                    if (val + dep < tree[pos].value) {
                        return false;
                    }
                }
            }
        } else {
            if ((tree[pos].value % 2) != (val % 2)) {
                return false;
            } else {
                if (tree[pos].value < val) {
                    if (val - dep > tree[pos].value) {
                        return false;
                    }
                } else if (tree[pos].value > val) {
                    if (val + dep < tree[pos].value) {
                        return false;
                    }
                } else {
                    ;
                }
            }
        }
    }
}



                    
                



bool dfs_ans(int pos, int val, int dep)
{
    if (tree[pos].check) {
        return true;
    } else {
        tree[pos].chech = true;
    }
    if (tree[pos].value != INF) {
        if (dep % 2) {
            if ((tree[pos].value % 2) == (val % 2)) {
                return false;
            } else if (val < tree[pos].value) {
                if ((val + dep) < tree[pos].value) {
                    return false;
                }
            } else {
                if ((val + dep) > tree[pos].value) {
                    return false;
                }
            } 
        } else {
            if ((tree[pos].value % 2) != (val % 2)) {
                return false;
            } else if (val < tree[pos].value) {
                if ((val + dep) < tree[pos].value) {
                    return false;
                }
            } else {
                if ((val + dep) > tree[pos].value) {
                    return false;
                }
            }
        }
        dfs(pos);
    } else {
        for (int i = 0; i < tree[pos].neighbor.size(); i++) {
            if (!dfs_tree(tree[pos].neighbor[i], val, dep+1)) {
                return false;
            }
        }
    }
}











