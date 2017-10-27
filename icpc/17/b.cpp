#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)

int main() {
	for (string s1, s2; cin >> s1&&s1 != ".";) {
		cin >> s2;
		vector<string> a1,a2;
		string b1, b2; // " ŠÜ‚Þ
		{
			bool l = false;
			string tmp = "";
			rep(i, 0, s1.size()) {
				if (l) {
					if (s1[i] == '"') {
						l = false;
						a1.push_back(tmp);
						tmp = "";
						b1 += s1[i];
						continue;
					}
					tmp += s1[i];
				}
				else {
					b1 += s1[i];
					if (s1[i] == '"') {
						l = true;
					}
				}
			}
		}
		{
			bool l = false;
			string tmp = "";
			rep(i, 0, s2.size()) {
				if (l) {
					if (s2[i] == '"') {
						l = false;
						a2.push_back(tmp);
						tmp = "";
						b2 += s2[i];
						continue;
					}
					tmp += s2[i];
				}
				else {
					b2 += s2[i];
					if (s2[i] == '"') {
						l = true;
					}
				}
			}
		}
		int cnt = 0;
		if (b1 != b2) {
			cout << "DIFFERENT" << endl;
		}
		else {
			rep(i, 0, a1.size()) {
				if (a1[i] != a2[i])
					cnt++;
			}
			if (cnt == 0) {
				cout << "IDENTICAL" << endl;
			}
			else if (cnt == 1) {
				cout << "CLOSE" << endl;
			}
			else {
				cout << "DIFFERENT" << endl;
			}
		}
	}
}