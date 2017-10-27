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
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

vi graph, score;
int n;

int search(int pos, int num)
{
    int ret = pos;
    if (score[pos] > num) {
        score[pos] = num;
        if (graph[pos]) {
            ret = search(pos + graph[pos], num);
        } else {
            return pos;
        }
    } else {
        return -1;
    }
    return ret;
}

signed main()
{
    cin >> n;
    graph = vi(n, 0);
    rep(i, n) {
        cin >> graph[i];
    }
    score = vi(n, INF);

    score[0] = 0;
    queue<int> que;
    que.push(0);

    int loop = 2;
    while (score[n-1] == INF) {
        int pos = que.front();
        que.pop();
        Rep(i, 7) {
            int nxt = pos + i;
            if (nxt >= n) nxt = n-1;
            if (score[pos]+1 < score[nxt]) {
                int tmp = search(nxt, score[pos]+1);
                if (tmp != -1) que.push(tmp);
            }
        }
    }

    cout << score[n-1] << endl;

    return 0;
}

