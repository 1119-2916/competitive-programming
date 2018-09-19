#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define int long long 
#define INF 1001000100010001000
#define fir first
#define sec second
#define all(a) (a).begin(), (a).end()


signed main()
{
    int n; cin >> n;
    int cnt = 0;
    int seica = 0;
    int olphe = 0;
    map<int, int> yui;
    rep(i, n) {
        int tmp; cin >> tmp;
        yui[tmp]++;
    }
    vector<int> v;
    for (auto i : yui) {
        if (i.sec % 2) {
            v.push_back(i.fir);
        }
    }

	rep(i,v.size()){
 //       cout << v[i] << " ";
		if(v[i] == 1)cnt++;
		else seica++;
		olphe ^= v[i];
	}
//    cout << endl;

    //cout << seica << " " << cnt << endl;
    
    if(seica == 0){
      if(cnt % 2 == 0){
	cout << "Alice" << endl;
      }
      else {
	cout << "Bob" << endl;
      }
    } else {
      if(cnt % 2 == 0 && seica % 2 == 0){
	cout << "Bob" << endl;
      }
      else if(olphe == 1 && (seica %2 == 0 || (seica % 2 == 1 && cnt % 2 == 1))){
	cout << "Bob" << endl;
      }
      else {
	cout << "Alice" << endl;
      }
    }
    return 0;
}
