#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1001000100010001000
#define vi vector<int>
#define pb push_back
#define all(a) (a).begin(), (a).end()

void Ti11192916(vector<int> a);

struct node {
    int ans, cnt, base;
    bool used;
    vector<int> next;
    node():ans(-1), used(false), cnt(0) {}
    void add(int a) {
        next.pb(a);
        cnt = next.size();
        base++;
    }
    void remove(int a) {
        if (next.size() == 0) return ;
        for (int i = 0; i < next.size(); i++) {
            if (next[i] == a) {
                next[i] = INF;
                break;
            }
        }
        sort(all(next));
        next.pop_back();
        //Ti11192916(next);
        cnt = next.size();
    }
    vi kyoko(int a) {
        ans = a;
        used = true;
        return next;
    }
};

vector<node> nodes;

signed main()
{
    int n;
    cin >> n;

    nodes = vector<node>(n*n, node());
    for (int i = 0; i < 2 * n * n - 2 * n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        nodes[a].add(b);
        nodes[b].add(a);
    }

    vector< vector<int> > yui(n, vi(n, -1));

    int ptr = -1;
    for (int i = 0; i < n * n; i++) {
        if (nodes[i].cnt == 2) {
            ptr = i;
            break;
        }
    }
    if (ptr == -1) {
        cout << "nande" << endl;
        return 0;
    }
    yui[0][0] = ptr+1;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (i == 0) {/*{{{*/
                //cout << "now " << yui[i][j] << endl;
                vi tmp = nodes[yui[i][j]-1].kyoko(0);
                for (int k = 0; k < tmp.size(); k++) {
                    nodes[tmp[k]].remove(yui[i][j]-1);
                    //cout << nodes[tmp[k]].next.size() << " ";
                }
                //cout << endl;
                if (nodes[tmp[0]].next.size() < 
                        nodes[tmp[1]].next.size()) {
                    yui[i][j+1] = tmp[0]+1;
                    yui[i+1][j] = tmp[1]+1;
                } else {
                    yui[i][j+1] = tmp[1]+1;
                    yui[i+1][j] = tmp[0]+1;
                }
                /*
                cout << tmp[0]+1 << " " << tmp[1]+1 << endl;
                cout << nodes[tmp[0]].next.size() << " " <<
                    nodes[tmp[1]].next.size() << endl;
                */
            } else {
                //cout << "now " << yui[i][j] << endl;
                vi tmp = nodes[yui[i][j]-1].kyoko(0);
                for (int k = 0; k < tmp.size(); k++) {
                    nodes[tmp[k]].remove(yui[i][j]-1);
                    //cout << nodes[tmp[k]].next.size() << " ";
                }
                //cout << endl;
                if (j != n-2) {
                    if (tmp[0]+1 == yui[i][j+1]) {
                        yui[i+1][j] = tmp[1] + 1;
                    } else {
                        yui[i+1][j] = tmp[0] + 1;
                    }
                } else {
                    if (nodes[tmp[0]].next.size() < 
                            nodes[tmp[1]].next.size()) {
                        yui[i][j+1] = tmp[0]+1;
                        yui[i+1][j] = tmp[1]+1;
                    } else {
                        yui[i][j+1] = tmp[1]+1;
                        yui[i+1][j] = tmp[0]+1;
                    }
                }
            }/*}}}*/
        }
        vi tmp = nodes[yui[i][n-1]-1].kyoko(0);
        for (int k = 0; k < tmp.size(); k++) {
            nodes[tmp[k]].remove(yui[i][n-1]-1);
            //cout << nodes[tmp[k]].next.size() << " ";
        }
    }

    vector< bool > used(n*n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n-1 && j == n-1) {
                for (int k = 0; k < n*n; k++) {
                    if (!used[k]) {
                        cout << k+1;
                        break;
                    }
                }
            } else {
                cout << yui[i][j] << " " ;
                used[yui[i][j]-1] = true;
            }
        }
        cout << endl;
    }

    return 0;
}



