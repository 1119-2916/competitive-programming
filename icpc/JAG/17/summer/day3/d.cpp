#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1001000100010001000
#define vi vector<int>
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i < n; i++)

int n;
vi rate;
vector< vi > hand;
vector< vector< double > > table;

double solve(int mem, int pos)
{
    if (table[pos][mem] != -1.0) return table[pos][mem];
    double ret = 0.0, sum = 0.0, lose = 0.0;
    for (int i = 1; i < mem; i++) {
        if (mem | i == mem) {
            double TIke = 1.0;
            for (int j = 0; j < n; j++) {
                if ((j & mem) && (j & i)) {
                    TIke *= hand[pos][j+1] / 100.0;
                } else if (j & mem) {
                    TIke *= hand[(pos+2)%3][j+1] / 100.0;
                }
            }
            ret += max(solve(i, (pos+1)%3), max(solve(i, pos),
                        solve(i, (pos+2)%3))) * TIke;
            sum += TIke;
        }
    }
    for (int i = 1; i < mem; i++) {
        if (mem | i == mem) {
            double TIke = 1.0;
            for (int j = 0; j < n; j++) {
                if ((j & mem) && (j & i)) {
                    TIke *= hand[pos][j+1] / 100.0;
                } else if (j & mem) {
                    TIke *= hand[(pos+1)%3][j+1] / 100.0;
                }
            }
            lose += TIke;
        }
    }
    cout << "call : " << mem << " " << pos << " " 
        << table[pos][mem] << "   " ;
    cout << sum << " " << lose << endl;
    sum = 1.0 - sum - lose;
    for (int i = 0; i < n; i++) {
        if (mem & i) {
            if (rate[i+1] > rate[0]) {
                sum = 0.0;
            }
        }
    }
    return table[pos][mem] = ret + sum;
}

signed main()
{
    cin >> n;
    rate = vi(n, 0);
    cin >> rate[0];
    hand = vector< vi >(3, vi(n));
    table = vector< vector< double > >(3, vector<double>((1<<n)-1, -1.0)); 
    //cout << table[0][0] << endl;

    Rep(i, n) {
        cin >> rate[i] >> hand[0][i] >> hand[1][i] >> hand[2][i];
    }

    Rep(i, n) {
        table[0][1 << (i-1)] = hand[2][i] / 100.0;
        if (rate[0] > rate[i]) {
            table[0][1 << (i-1)] += hand[0][i] / 100.0;
        }
        table[1][1 << (i-1)] = hand[0][i] / 100.0;
        if (rate[0] > rate[i]) {
            table[1][1 << (i-1)] += hand[1][i] / 100.0;
        }
        table[2][1 << (i-1)] = hand[1][i] / 100.0;
        if (rate[0] > rate[i]) {
            table[2][1 << (i-1)] += hand[2][i] / 100.0;
        }
    }

    rep(i, 3) {
        rep(j, table[0].size()) {
            cout << table[i][j] << " " ;
        }
        cout << endl;
    }

    printf("%.10lf\n", max(solve((1<<(n-1))-1,0),max(solve((1<<(n-1))-1,1),
            solve((1<<(n-1))-1, 2))));

    cout << endl;
    rep(i, 3) {
        rep(j, table[0].size()) {
            cout << table[i][j] << " " ;
        }
        cout << endl;
    }

    return 0;
}



