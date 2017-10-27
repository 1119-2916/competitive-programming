
#define Edge pair< i_i, int>
#define Graph vector< vp >

//単一始点最短経路(負閉路なし)
//Dijkstra O((E+V)logV)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
vector<int> dijkstra(Graph &g, int s, vi &dist)
{
    int n = g.size();
    vi visited(n, 0); visited[s] = 1;
    vi prev(n, -1);
    dist.assign(n, INF); dist[s] = 0;
    priority_queue< Edge, vector< Edge >, greater< Edge > > pq;
    pq.push(Edge(i_i((int)0, s), (int)-1)); // コスト 今 前
    while (pq.size()) {
        int d = pq.top().ffir, v = pq.top().fsec, u = pq.top().second;
        pq.pop();
        if (dist[v] < d) continue; //すでに最短でなければ無視
        visited[v] = 2; prev[v] = u;
        for (int i = 0; i < g[v].size(); i++) {
            i_i &e = g[v][i];
//        for (i_i &e : g[v]) {
            if (visited[e.fir] == 2) continue;
            if (dist[e.fir] > dist[v] + e.sec) {
                dist[e.fir] = dist[v] + e.sec;
                pq.push(Edge(i_i(dist[e.fir], e.fir), v));
                visited[e.fir] = 1;
            }
        }
    }
    return prev;
}

