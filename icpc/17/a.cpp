#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int n, m; cin >> n >> m&&n;) {
		vector<int> a(n);
		int ans = 0;
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (a[i] + a[j] > m)continue;
			ans = max(ans, a[i] + a[j]);
		}
		if (ans == 0)cout << "NONE" << endl;
		else cout << ans << endl;
	}
}