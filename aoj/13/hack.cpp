#include<bits/stdc++.h>
using namespace std;
#define P pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second



struct UnionFind
{

    vector<int> par;
    vector<int> sizes;

    UnionFind(int n) : par(n), sizes(n, 1) {
        rep(i,n) par[i] = i;
    }

    int root(int x) {
        if (x == par[x]) return x;
        return par[x] = root(par[x]); 
    }

    bool unite(int x, int y) {

        x = root(x);
        y = root(y);

        if (x == y) return false;

        if (sizes[x] < sizes[y]) swap(x, y);

        par[y] = x;
        sizes[x] += sizes[y];

        return true;
    }

    bool find(int x,int y){
        return root(x)==root(y);
    }

    int size(int x) {
        return sizes[root(x)];
    }
};

signed main(){
    int n,m;
    vector<int> v[200100];
    cin>>n>>m;
    UnionFind uf(n);

    vector<P> a;

    rep(i,m){
        int x,y;
        cin>>x>>y;
        y--;
        v[y].PB(x);
        if(y!=n-1)v[y+1].PB(x);
        a.PB(P(x,y));
    }

    rep(i,n){
        sort(all(v[i]));
    }
    sort(all(a));

    int ans[200010];
    rep(i,n){
        ans[i]=1;
    }

    rep(i,n){
        P p=a[i];
        int x,y;
        x=a[i].S;
        y=a[i].S+1;
        uf.unite(x,y);
        if(upper_bound(all(v[x]),p.F)==v[x].end()){
            ans[x]=uf.size(x);
        }
        if(upper_bound(all(v[y]),p.F)==v[y].end()){
            ans[y]=uf.size(y);
        }
    }



    rep(i,n){
        if(i) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;

}
