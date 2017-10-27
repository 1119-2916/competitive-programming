#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define INF 1010001000
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef pair<int, int> i_i;
typedef long long int llong;
typedef pair<llong, llong> ll_ll;
typedef struct edge {int f, t;}Edge;
typedef pair<i_i, string> era;


int main()
{
    int n, m;
    while(cin >> n >> m, n) {
        vector<era> data;
        rep(i, n) {
            era tmp;
            cin >> tmp.second >> tmp.first.second >> tmp.first.first;
            data.pb(tmp);
            if (tmp.first.second != 1) {
                tmp.first.first -= tmp.first.second - 1;
                tmp.first.second = 1;
                data.pb(tmp);
            }
        }
        sort(data.begin(), data.end());
        int pt = 1;
        for (int i = 1; i < data.size(); i++) {
            if (data[i-1] != data[i]) {
                data[pt++] = data[i];
            } else {
                data[pt] = data[i];
            }
        }
        rep(i, m) {
            int tmp;
            bool fl = false;
            cin >> tmp;
            if (pt != 1) {
                if (data[0].first.first == tmp) {
                    cout << data[0].second << " " 
                        << data[0].first.second << endl;
                    fl = true;
                } else {
                    for (int j = 1; j < pt; j++) {
                        if (data[j].first.first == tmp) {
                            cout << data[j].second << " " 
                                << data[j].first.second << endl;
                            fl = true;
                            break;
                        }
                        if (data[j-1].first.first <= tmp && 
                                tmp <= data[j].first.first) {  
                            if (data[j-1].second == data[j].second) {
                                cout << data[j].second << " ";
                                cout << data[j-1].first.second + tmp 
                                    - data[j-1].first.first << endl;
                            } else {
                                cout << "Unknown" << endl;
                            }
                            fl = true;
                            break;
                        }
                    }
                }
            } else {
                if (data[0].first.first == tmp) {
                    cout << data[0].second << " 1" << endl;
                    fl = true;
                }
            }
            if (!fl) {
                cout << "Unknown" << endl;
            }
        }
    }
    return 0;
}
