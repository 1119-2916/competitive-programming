#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)

int n, m;
int ike[11][11];

bool inrange(int i, int j) {
	return 0 <= i&&i < n && 0 <= j&&j < m;
}
//
//int solve(int depth) {
//	int maxi = 0;
//	vector<vector<bool>> used(h, vector<bool>(w));
//	rep(i, 0, h) {
//		rep(j, 0, h) {
//			if (used[i][j] == false && ike[i][j] < depth) {
//				maxi = max(maxi, bfs(i, j, used));
//			}
//		}
//	}
//}
//
//int di[] = { 0,1,0,-1 };
//int dj[] = { 1,0,-1,0 };
//using P = pair<int, int>;
//int bfs(int i, int j, vector<vector<bool>> &used) {
//	queue<P> q;
//	q.emplace(i, j);
//	while (q.size()) {
//		int
//	}
//}
//
//int dp[11][11];
//void largest_rectangle_in_a_histogram(const vector<int> &h) {
//	int n = h.size();
//	stack<P> st;
//	st.emplace(-1, -1);
//	int area = 0;
//	rep(i, 0, n) {
//		if (st.top().first == h[i])
//			continue;
//		int pos = i;
//		while (st.top().first >= h[i]) {
//			area = max(area, st.top().first*(i - st.top().second));
//			pos = st.top().second;
//			st.pop();
//		}
//		st.emplace(h[i], pos);
//	}
//	while (st.size()) {
//		area = max(area, st.top().first*(n - st.top().second));
//		st.pop();
//	}
//	return area;
//}
//
//int largest_rectangle(vector<vector<int>> v) {
//	int H = v.size(), W = v.front().size());
//	//rep(i, 0, H - 1)rep(j, 0, W) {
//	//	if (v[i + 1][j] == 0)continue;
//	//	v[i + 1][j] += v[i][j];
//	//}
//	int area = 0;
//	rep(i, 0, H)
//		area = max(area, largest_rectangle_in_a_histogram(v[i]));
//	return area;
//}

int main() {
	for (; cin >> n >> m && n;) {
		rep(i, 0, n)rep(j, 0, m) {
			cin >> ike[i][j];
		}
		int ans = 0;
		using P = pair<int, int>;
		rep(k, 0, 10) {
			vector<set<P>> st(n);
			vector<map<P, int>> area(n);
			rep(i, 0, n) {
				int l, r;
				l = 0, r = 0;
				int a = 0;
				rep(j, 0, m) {
					if (ike[i][j] <= k) {
						r++;
						a += k + 1 - ike[i][j];
					}
					else {
						if (ike[i][l] <= k) {
							st[i].emplace(l, r);
							area[i][P(l, r)] = a;
						}
						a = 0;
						l = j + 1;
						r = j + 1;
					}
				}
				if (l != m) {
					st[i].emplace(l, r);
					area[i][P(l, r)] = a;
				}
			}

			//cout << "k " << k << endl;

			//rep(i, 0, h) {
			//	cout << " i " << i << endl;
			//	for (auto it = st[i].begin(); it != st[i].end(); it++) {
			//		cout << "  " << (*it).first << " " << (*it).second << " area:" << area[i][*it] << endl;
			//	}
			//}

			rep(i, 1, n - 1) {
				//cout << " i " << i << endl;
				for (auto it = st[i].begin(); it != st[i].end(); it++) {
					int l, r; tie(l, r) = *it;
					P p = *it;
					if (l == 0 || r == m)continue;
					int tmp = area[i][p];
					// æ“ª‚Ì‚â‚Â
					{
						int ni = i - 1;
						if (st[ni].size() != 0) {
							auto nit = st[ni].lower_bound(p);

							// end ‚Ìê‡
							if (nit == st[ni].end()) {
								auto npit = nit; npit--;

								int nl, nr;
								tie(nl, nr) = *npit;
								if (nr < l) {
								}
								else {
									continue;
								}
							}
							else {
								P np = *nit;
								int nl, nr;
								tie(nl, nr) = np;

								if (p == np)
									continue;
								else if (nl <= r) {
									continue;
								}
								else if (r < nl) {
									if (nit == st[ni].begin()) {
									}
									else {
										auto npit = nit; npit--;
										tie(nl, nr) = *npit;
										if (nr < l) {
										}
										else {
											continue;
										}
									}
								}
							}
						}

					}


					//cout << "  " << (*it).first << " " << (*it).second << " area:" << area[i][*it] << endl;


					rep(ni, i + 1, n) {
						if (st[ni].size() == 0) {
							break;
						}

						auto nit = st[ni].lower_bound(p);

						// end ‚Ìê‡
						if (nit == st[ni].end()) {
							auto npit = nit; npit--;

							int nl, nr;
							tie(nl, nr) = *npit;
							if (nr < l) {
								break;
							}
							else {
								tmp = 0;
								break;
							}
						}
						else {
							P np = *nit;
							int nl, nr;
							tie(nl, nr) = np;

							if (p == np) {
								if (ni == n - 1) {
									tmp = 0;
									break;
								}
								tmp += area[ni][np];
							}
							else if (nl <= r) {
								tmp = 0;
								break;
							}
							else if (r < nl) {
								if (nit == st[ni].begin()) {
									// ok
									break;
								}
								auto npit = nit; npit--;
								tie(nl, nr) = *npit;
								if (nr < l) {
									// ok
									break;
								}
								else {
									tmp = 0;
									break;
								}
							}
						}
					}
					//cout << "tmp" << " " << tmp << endl;
					ans = max(ans, tmp);
				}
			}

		}
		cout << ans << endl;
	}
}