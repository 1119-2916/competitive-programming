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
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

#define date pair<i_i, i_i>

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm

int n, k, m;
vector<date> data;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m >> k;
    rep(i, m) {
        date tmp;
        cin >> tmp.ffir >> tmp.fsec >> tmp.sfir >> tmp.ssec;
        data.pb(tmp);
    }
    sort(all(data));
    vi score(n+1, INF);
    vp go;
    int sum = 0, cnt = 0;
    rep(i, m) {
        int time = data[i].ffir;
        if (data[i].fsec) {
            if (score[data[i].fsec] == INF) {
                score[data[i].fsec] = data[i].ssec;
                sum += data[i].ssec;
                cnt++;
            } else if (score[data[i].fsec] > data[i].ssec) {
                sum -= score[data[i].fsec] - data[i].ssec;
                score[data[i].fsec] = data[i].ssec;
            } else {
                continue;
            }
            if (cnt == n) {
                go.pb(i_i(time, sum));
            }
        }
    }
    /*
    cout << endl;
    rep(i, go.size()) {
        std::cout << go[i].fir << " " << go[i].sec << std::endl;
    }
    cout << endl;
    */

    score = vi(n+1, INF);
    vp back;
    sum = 0, cnt = 0;
    for (int i = m-1; i >= 0; i--) {
        int time = data[i].ffir;
        if (data[i].sfir) {
            if (score[data[i].sfir] == INF) {
                score[data[i].sfir] = data[i].ssec;
                sum += data[i].ssec;
                cnt++;
            } else if (score[data[i].sfir] > data[i].ssec) {
                sum -= score[data[i].sfir] - data[i].ssec;
                score[data[i].sfir] = data[i].ssec;
            } else {
                continue;
            }
            if (cnt == n) {
                back.pb(i_i(time, sum));
            }
        }
    }
    /*
    rep(i, back.size()) {
        std::cout << back[i].fir << " " << back[i].sec << std::endl;
    }
    */

    if (!go.size() || !back.size()) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int ans = INF, now = INF, ptr = 0, backscore = INF;
    for (int i = go.size()-1; i >= 0; i--) {
        now = go[i].sec;
        int time = go[i].fir;
        while (ptr < back.size() && time + k < back[ptr].fir) {
            backscore = min(backscore, back[ptr].sec);
            ptr++;
        }
        ans = min(ans, backscore + now);
        /*
        std::cout << ans << " " << " " << now << " " << backscore
            << " " << ptr << std::endl;
            */
    }
    if (ans == INF) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << ans << std::endl;
    }



    return 0;
}





