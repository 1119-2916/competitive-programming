#include<bits/stdc++.h>

#define MOD 1000000007
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

using namespace std;
using Int = long long;

struct SCC{
    vector<vector<int> > G,R,T,C;
    vector<int> vs,used,blg;
    SCC(){}
    SCC(int n):G(n),R(n),used(n),blg(n){}

    void add_edge(int u,int v){
        G[u].emplace_back(v);
        R[v].emplace_back(u);
    }

    void dfs(int v){
        used[v]=1;
        for(int u:G[v])
            if(!used[u]) dfs(u);
        vs.emplace_back(v);
    }

    void rdfs(int v,int k){
        used[v]=1;
        blg[v]=k;
        C[k].emplace_back(v);
        for(int u:R[v])
            if(!used[u]) rdfs(u,k);
    }

    int build(){
        int n=G.size();
        for(int v=0;v<n;v++)
            if(!used[v]) dfs(v);

        fill(used.begin(),used.end(),0);
        int k=0;
        for(int i=n-1;i>=0;i--){
            if(!used[vs[i]]){
                T.emplace_back();
                C.emplace_back();
                rdfs(vs[i],k++);
            }
        }
        for(int v=0;v<n;v++)
            for(int u:G[v])
                if(blg[v]!=blg[u])
                    T[blg[v]].push_back(blg[u]);

        for(int i=0;i<k;i++){
            sort(T[i].begin(),T[i].end());
            T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
        }
        return k;
    }
    int operator[](int k) const{return blg[k];};
};

//BEGIN CUT HERE
struct TwoSat{
    int n;
    SCC scc;
    TwoSat(int n):n(n),scc(n*2){}
    int negate(int v){return (n+v)%(n*2);}
    void add_if(int u,int v){
        // u -> v <=> !v -> !u
        scc.add_edge(u,v);
        scc.add_edge(negate(v),negate(u));
    }
    void add_or(int u,int v){
        // u or v <=> !u -> v
        add_if(negate(u),v);
    }
    void add_nand(int u,int v){
        // u nand v <=> u -> !v
        add_if(u,negate(v));
    }
    void set_true(int v){
        //  v <=> !v ->  v
        scc.add_edge(negate(v),v);
    }
    void set_false(int v){
        // !v <=>  v -> !v
        scc.add_edge(v,negate(v));
    }
    vector<int> build(){
        scc.build();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(scc[i]==scc[n+i]) return {};
            res[i]=scc[i]>scc[n+i];
        }
        return res;
    }
};

/*
signed CFR441_C(){
    int n,m;
    scanf("%d %d",&n,&m);

    vector<vector<int>> G(n);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        G[i].assign(k,0);
        for(int &v:G[i]){
            scanf("%d",&v);
            v--;
        }
    }
    auto NG=[](){puts("No");exit(0);};

    TwoSat ts(m);
    auto add_edge=
        [&](vector<int> &as,vector<int> &bs){
            int x=min(as.size(),bs.size());
            int i;
            for(i=0;i<x;i++){
                if(as[i]==bs[i]) continue;
                if(as[i]<bs[i]){
                    ts.add_if(bs[i],as[i]);
                }else{
                    ts.set_true(as[i]);
                    ts.set_false(bs[i]);
                }
                break;
            }
            if((i==x)&&(as.size()>bs.size())) NG();
        };

    for(int i=0;i+1<n;i++)
        add_edge(G[i],G[i+1]);

    auto vs=ts.build();
    if(vs.empty()) NG();

    vector<int> ans;
    for(int i=0;i<m;i++)
        if(vs[i]) ans.emplace_back(i);

    puts("Yes");
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++){
        if(i) printf(" ");
        printf("%d",ans[i]+1);
    }
    puts("");

    return 0;
}
*/
/*
   verified 2019/06/20
http://codeforces.com/contest/875/problem/C
*/

/*
signed YUKI_274(){
    int n,m;
    cin>>n>>m;
    vector<int> l(n),r(n);
    for(int i=0;i<n;i++) cin>>l[i]>>r[i],r[i]++;

    auto check=[&](int al,int ar,int bl,int br){
        return max(al,bl)<min(ar,br);};

    TwoSat ts(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(check(l[i],r[i],l[j],r[j])) ts.add_nand(i,j);
            if(check(l[i],r[i],m-r[j],m-l[j])) ts.add_nand(i,ts.negate(j));
            if(check(m-r[i],m-l[i],l[j],r[j])) ts.add_nand(ts.negate(i),j);
            if(check(m-r[i],m-l[i],m-r[j],m-l[j]))
                ts.add_nand(ts.negate(i),ts.negate(j));
        }
    }

    cout<<(ts.build().empty()?"NO":"YES")<<endl;
    return 0;
}
*/
/*
   verified 2019/06/20
https://yukicoder.me/problems/no/274
*/

int dy1[] = {0, 1,
          0, 1,
          0, 1, 2, 3, 4,
          0, 1, 2, 3, 4,
          0, 1, 2, 3, 4,
          0, 1, 2, 3, 4,
          0, 1, 2, 3, 4};
int dx1[] = {-2, -2,
          -1, -1,
          0, 0, 0, 0, 0,
          1, 1, 1, 1, 1,
          2, 2, 2, 2, 2,
          3, 3, 3, 3, 3,
          4, 4, 4, 4, 4};

int dy2[] = {3, 4,
          3, 4,
          0, 1, 2, 3, 4,
          0, 1, 2, 3, 4,
          0, 1, 2, 3, 4,
          0, 1, 2, 3, 4,
          0, 1, 2, 3, 4};
int dx2[] = {-2, -2,
          -1, -1,
          0, 0, 0, 0, 0,
          1, 1, 1, 1, 1,
          2, 2, 2, 2, 2,
          3, 3, 3, 3, 3,
          4, 4, 4, 4, 4};
int dxyn = 29;


signed YUKI_470(){

    int2(h, w);
    vector<string> table(h);
    rep(i, h) {
        cin >> table[i];
    }

    vector<pii> couples(h * w);

    rep(p, dxyn) {
        for (int a = -200; a < 201; a++) {
            for (int b = -200; b < 201; b++) {
                int i = dx1[p] + 5 * a + 2 * b, j = dy1[p] - 2 * a + 5 * b;
                if (in(i, 0, h) && in(j, 0, w) && table[i][j] == '.') {
                    couples[i * w + j].first = p+1;
                }
            }
        }
    }

    rep(p, dxyn) {
        for (int a = -200; a < 201; a++) {
            for (int b = -200; b < 201; b++) {
                int i = dx2[p] + 2 * a + 5 * b, j = dy2[p] - 5 * a + 2 * b;
                if (in(i, 0, h) && in(j, 0, w) && table[i][j] == '.') {
                    couples[i * w + j].second = p+1;
                }
            }
        }
    }

    //togasat::Solver toga_sat;
    TwoSat ts(dxyn);
    //vector<int> clause(2);
/*
    rep(i, h) {
        rep(j, w) {
            cout << couples[i * w + j].fir << " , " <<
                couples[i * w + j].sec << " | ";
        }
        cout << endl;
    }
*/
    //map<int, bool> ans;
    rep(i, couples.size()) {
        //cout << couples[i].fir << " " << couples[i].sec << endl;
        if (couples[i].fir && couples[i].sec) {
            //clause[0] = couples[i].fir;
            //clause[1] = couples[i].sec;
            //toga_sat.addClause(clause);
            //ans[couples[i].fir] = false;
            //ans[couples[i].sec] = false;
            ts.add_or(couples[i].fir, couples[i].sec);
        }
    }

    //togasat::lbool status = toga_sat.solve();
    //cout << toga_sat.get_answer() << endl;
    auto res=ts.build();

    rep(i, dxyn) {
        cout << res[i] << endl;
    }

    int ret = 0;
    for(int i=0;i<dxyn;i++){
        if(res[i]) ret++;
            //cout<<u[i][0]<<u[i][1]<<" "<<u[i][2]<<endl;
        //else
         //   cout<<u[i][0]<<" "<<u[i][1]<<u[i][2]<<endl;
    }
    cout << ret << endl;
}

/*
signed YUKI_470(){
    int n;
    cin>>n;
    vector<string> u(n);
    for(int i=0;i<n;i++) cin>>u[i];

    auto NO=[](){cout<<"Impossible"<<endl;exit(0);};

    if(n>=100) NO();

    TwoSat ts(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            auto &as=u[i];
            auto &bs=u[j];
            if(as[0]==bs[0]&&as[1]==bs[1])
                ts.add_nand(i,j);

            if(as[0]==bs[1]&&as[1]==bs[2])
                ts.add_nand(i,ts.negate(j));

            if(as[1]==bs[0]&&as[2]==bs[1])
                ts.add_nand(ts.negate(i),j);

            if(as[1]==bs[1]&&as[2]==bs[2])
                ts.add_nand(ts.negate(i),ts.negate(j));

            if(as[0]==bs[0]) ts.add_nand(ts.negate(i),ts.negate(j));
            if(as[0]==bs[2]) ts.add_nand(ts.negate(i),j);
            if(as[2]==bs[0]) ts.add_nand(i,ts.negate(j));
            if(as[2]==bs[2]) ts.add_nand(i,j);
        }
    }

    auto res=ts.build();
    if(res.empty()) NO();

    for(int i=0;i<n;i++){
        if(res[i])
            cout<<u[i][0]<<u[i][1]<<" "<<u[i][2]<<endl;
        else
            cout<<u[i][0]<<" "<<u[i][1]<<u[i][2]<<endl;
    }
    return 0;
}
//*
   verified 2019/06/20
https://yukicoder.me/problems/no/470
*/

signed main(){
    //CFR441_C();
    //YUKI_274();
    YUKI_470();
    return 0;
}
