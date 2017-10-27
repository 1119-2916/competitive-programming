#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

#define loop(i, n) for (int i = 1; i < n; i++)
#define INF 1010001000

typedef pair<int, int> i_i;
typedef pair<double, int> d_i;

double calc(i_i &a, i_i &b);
void dijkstra(int st, int en, vector<vector<double> > &g);
void print(int st, int en, vector<int> &path);

int n;

int main()
{
    cin >> n;
    while (n) {
        n++;
        vector<vector<double> > g(n, vector<double>(n));
        vector<i_i > ob(n);
        loop(i, n) {
            int a;
            cin >> a;
            cin >> ob[a].first >> ob[a].second;
        }
        loop(i, n) {
            loop(j, n) {
                g[i][j] = calc(ob[i], ob[j]);
            }
        }
        int m;
        cin >> m;
        m++;
        loop(i, m) {
            int a, b;
            cin >> a >> b;
            dijkstra(a, b, g);
        }
        cin >> n;
    }
    return 0;
}

void dijkstra(int st, int en, vector<vector<double> > &g)
{
    priority_queue<d_i, vector<d_i>, greater<d_i> > pq;
    vector<double> d(n, INF);
    vector<int> prev(n, -1);
    d[st] = 0;
    pq.push(make_pair(0.0, st));

    while (!pq.empty()) {
        d_i tmp = pq.top();
        pq.pop();
        int v = tmp.second;
        if (d[v] < tmp.first) {
            continue;
        }
        for (int i = 1; i < n; i++) {
            if (d[i] > d[v] + g[v][i]) {
                d[i] = d[v] + g[v][i];
                prev[i] = v;
                pq.push(i_i(d[i], i));
            }
        }
    }
    if (d[en] != INF) {
        print(st, en, prev);
        cout << en << endl;
    } else {
        cout << "NA" << endl;
    }
}

void print(int st, int en, vector<int> &path)
{
    int wt = path[en];
    if (wt != st) {
        print(st, wt, path);
    }
    cout << wt << " ";
}
        

double calc(i_i &a, i_i &b) 
{
    int x1 = a.first, x2 = b.first, y1 = a.second, y2 = b.second;
    int tmp = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
    double len = sqrt((double)tmp);
    return (50.0000<len)?INF:len;
}

