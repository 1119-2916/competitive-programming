#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1010001000

typedef pair<int, int> i_i;


int main()
{
    int n, a, b;
    cin >> n;

    vector<vector<int> > G(n);

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);
    }

    vector<int> data(n, INF);
    priority_queue<i_i > pq;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        data[--a] = b;
        pq.push(i_i(b, a));
    }

    while (!pq.empty()) {
        i_i p = pq.top(); pq.pop();
        int u = p.second;
        for (int v: G[u]) {
            if (data[v] == INF) {
                data[v] = data[u] - 1;
                pq.push( i_i(data[v], v));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j: G[i]) {
            if (abs(data[i] - data[j]) != 1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << endl;
    }
    return 0;
}

