#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define MAX_N 201000

using namespace std;

int n, k, l;
int par_line[MAX_N];
int rank_line[MAX_N];
int par_road[MAX_N];
int rank_road[MAX_N];

void init(int n);
int find_line(int x);
int find_road(int x);
void unite_line(int x, int y);
void unite_road(int x, int y);
bool same_line(int x, int y);
bool same_road(int x, int y);

int main()
{
    cin >> n >> k >> l;
    init(n);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        unite_road(a-1, b-1);
    }
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        unite_line(a-1, b-1);
    }

    vector<int> road(n), line(n);
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        road[i] = find_road(i);
        line[i] = find_line(i);
        if (road[i] == line[i]) {
            ans[road[i]]++;
        }
    }
    for (int i = 0; i < n-1; i++) {
        cout << ans[road[i]] << " ";
    }
    cout << ans[n-1] << endl;
    return 0;
}


void init(int n) {
    for (int i = 0; i < n; i++) {
        par_line[i] =  i;
        rank_line[i] = 0;
        par_road[i] =  i;
        rank_road[i] = 0;
    }
}

int find_line(int x) {
    if (par_line[x] == x) {
        return  x;
    } else {
        return par_line[x] = find_line(par_line[x]);
    }
}

int find_road(int x) {
    if (par_road[x] == x) {
        return  x;
    } else {
        return par_road[x] = find_road(par_road[x]);
    }
}

void unite_line(int x, int y) {
    x = find_line(x);
    y = find_line(y);
    if (x == y) {
        return ;
    }

    if (x > y) {
        par_line[x] = y;
    } else {
        par_line[y] = x;
    }
}

void unite_road(int x, int y) {
    x = find_road(x);
    y = find_road(y);
    if (x == y) {
        return ;
    }

    if (x > y) {
        par_road[x] = y;
    } else {
        par_road[y] = x;
    }
}

bool same_line(int x, int y) {
    return find_line(x) == find_line(y);
}

bool same_road(int x, int y) {
    return find_road(x) == find_road(y);
}
