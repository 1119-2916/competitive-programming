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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dij geo2 kruskal graph uf

signed main()
{
    vb can(26, false);
    string a;
    cin >> a;
    rep(i, a.size()) {
        can[a[i] - 'a'] = true;
    }
    string data;
    cin >> data;
    bool star = false;
    string other;
    rep(i, data.size()) {
        if (data[i] == '*') {
            star = true;
        } else {
            other.pb(data[i]);
        }
    }

    Int(q);
    while (q--) {
        string query;
        cin >> query;
        if (!star) {
            if (query.size() != data.size()) {
                std::cout << "NO" << std::endl;
            } else {
                bool ret = true;
                rep(i, query.size()) {
                    if (data[i] != '?' && query[i] != data[i]) {
                        ret = false;
                        break;
                    } else if (data[i] == '?') {
                        if (!can[query[i]-'a']) {
                            ret = false;
                            break;
                        }
                    }
                }
                if (ret) {
                    std::cout << "YES" << std::endl;
                } else {
                    std::cout << "NO" << std::endl;
                }
            }
        } else {
            if (data.size()-1 == query.size()) {
                bool ret = true;
                rep(i, query.size()) {
                    if (other[i] != '?' && query[i] != other[i]) {
                        ret = false;
                        break;
                    } else if (other[i] == '?') {
                        if (!can[query[i]-'a']) {
                            ret = false;
                            break;
                        }
                    }
                }
                if (ret) {
                    std::cout << "YES" << std::endl;
                } else {
                    std::cout << "NO" << std::endl;
                }
            } else if (data.size() > query.size()) {
                std::cout << "NO" << std::endl;
            } else {

                bool ret = true;
                int left = 0, right = 0;
                rep(i, data.size()) {
                    if (data[i] != '*') {
                        if (data[i] != '?' && query[i] != data[i]) {
                            ret = false;
                            break;
                        } else if (data[i] == '?') {
                            if (!can[query[i]-'a']) {
                                ret = false;
                                break;
                            }
                        }
                    } else {
                        left = i;
                        break;
                    }
                }
                rep(i, data.size()) {
                    if (data[data.size()-1-i] != '*') {
                        if (data[data.size()-1-i] != '?' &&
                                query[query.size()-1-i] != data[data.size()-1-i]) {
                            ret = false;
                            break;
                        } else if (data[data.size()-1-i] == '?') {
                            if (!can[query[query.size()-1-i]-'a']) {
                                ret = false;
                                break;
                            }
                        }
                    } else {
                        right = query.size()-i;
                        break;
                    }
                }
                //            cout << "(" << left << "," << right << ")" << endl;
                for (int i = left; i < right; i++) {
                    if (can[query[i]-'a']) {
                        ret = false;
                        break;
                    }
                }
                if (ret) {
                    std::cout << "YES" << std::endl;
                } else {
                    std::cout << "NO" << std::endl;
                }
            }
        }
    }
    return 0;
}
