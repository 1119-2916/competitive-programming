#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
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


int main()
{
    int n;
    while (cin >> n, n) {
        vector<int> in(n);
        rep(i, n) {
            string st;
            cin >> st;
            in[i] = st.length();
        }
        bool ret = false;
        rep(i, n) {
            int tnk = 0, state = 0;
            if (ret) {
                break;
            }
            for (int j = i; j < n; j++) {
                if (state == 0) {
                    tnk += in[j];
                    if (tnk == 5) {
                        state++;
                        tnk = 0;
                    } else if (tnk > 5) {
                        break;
                    }
                } else if (state == 1) {
                    tnk += in[j];
                    if (tnk == 7) {
                        state++;
                        tnk = 0;
                    } else if (tnk > 7) {
                        break;
                    }
                } else if (state == 2) {
                    tnk += in[j];
                    if (tnk == 5) {
                        state++;
                        tnk = 0;
                    } else if (tnk > 5) {
                        break;
                    }
                } else if (state == 3) {
                    tnk += in[j];
                    if (tnk == 7) {
                        state++;
                        tnk = 0;
                    } else if (tnk > 7) {
                        break;
                    }
                } else if (state == 4) {
                    tnk += in[j];
                    if (tnk == 7) {
                        cout << i+1 << endl;
                        ret = true;
                        break;
                    } else if (tnk > 7) {
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
