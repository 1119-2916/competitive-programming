#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#define INF 1010001000


using namespace std;

int cost[100001][100001];
int mincost[100001];
bool used[100001];
int V;

int main()
{







    return 0;
}

int prim() {
    for (int i = 0; i < V; i++) {
        mincost = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;
    
    while (true) {
        int v = -1;
        for (int u = 0; u < V; u++) {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }

        if (v == -1) break;
        used[v] = 


