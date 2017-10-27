
//木の直径
Edge diameter(const Graph &g, int s = 0) {
	Array dist;
	dijkstra(g, s, dist);
	int n = g.size(), u = -1, v = -1;
	for (int i = 0; i < n; i++) if (dist[i] != INF && (u == -1 || dist[i] > dist[u])) u = i;
	dijkstra(g, u, dist);
	for (int i = 0; i < n; i++) if (dist[i] != INF && (v == -1 || dist[i] > dist[v])) v = i;
	Weight d = dist[v];
	if (u > v) swap(u, v);
	return Edge(u, v, d);
}

//木の高さ
//戻り値: 各頂点からの最遠距離
Array height(const Graph &g) {
	Edge e = diameter(g);
	Array dist1, dist2;
	dijkstra(g, e.s, dist1);
	dijkstra(g, e.d, dist2);
	int n = g.size();
	Array height(n);
	for (int i = 0; i < n; i++)
		height[i] = max(dist1[i], dist2[i]);
	return height;
}

//木の深さ
//戻り値: 各ノードから根ノードまでのエッジ数
vector<int> depth(const Graph &g, int root) {
	vector<int> ret(g.size(), INF);
	using State = tuple<int, int, int>; //ノード 親 深さ
	stack<State> st; st.emplace(root, -1, 0);
	while (st.size()) {
		int s, p, d; tie(s, p, d) = st.top(); st.pop();
		ret[s] = d;
		for (auto &e : g[s]) {
			if (e.d == p)continue;
			st.emplace(e.d, s, d + 1);
		}
	}
	return ret;
}

//有向森（有向木）の深さ
using P = pair<int, int>; //深さ 根
vector<P> depth(const Graph &g) {
	int n = g.size();
	vector<P> ret(n);
	for (int i = 0; i < n; i++)
		ret[i] = P(0, i);
	vector<bool> isroot(n, true);
	for (int i = 0; i < n; i++)
		for (auto &e : g[i])
			isroot[e.d] = false;
	using State = tuple<int, int, int>; //ノード 根 深さ
	stack<State> st;
	dump(isroot);
	for (int i = 0; i < n; i++)
		if (isroot[i])
			st.emplace(i, i, 0);
	while (st.size()) {
		int s, r, d; tie(s, r, d) = st.top(); st.pop();
		ret[s] = P(d, r);
		for (auto &e : g[s])
			st.emplace(e.d, d + 1);
	}
	return ret;
}
