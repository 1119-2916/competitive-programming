#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1001000100010001000
#define vi vector<int>
#define pb push_back
#define all(a) (a).begin(), (a).end()

using Weight = int;
struct Edge{
    int s,d;Weight w;
    Edge(){};
    Edge(int s,int d,Weight w):s(s),d(d),w(w){};
};

using Edges=vector<Edge>;
using Graph=vector<Edges>;
using Array=vector<Weight>;
using Matrix=vector<Array>;

void addArc(Graph &g,int s,int d,Weight w=1){
    g[s].emplace_back(s,d,w);
}
void addEdge(Graph &g,int a,int b,Weight w=1){
    addArc(g,a,b,w);
    addArc(g,b,a,w);
}

auto dijkstra=[&](const Graph &g,int s,Array &dist){
    int n=g.size();
    vector<bool> vis(n);
    vector<int> prev(n,-1);
    dist.assign(n,INF);dist[s]=0;
    using State=tuple<Weight,int,int>;
    priority_queue<State,vector<State>,greater<State>>pq;
    pq.emplace(0,s,-1);
    while(pq.size()){
        Weight d;int v,p; tie(d,v,p)=pq.top();pq.pop();
        if(dist[v]<d)continue;
        vis[v]=true;
        prev[v]=p;
        for(auto &e:g[v]){
            if(vis[e.d])continue;
            if(dist[e.d]>dist[v]+e.w){
                dist[e.d]=dist[v]+e.w;
                pq.emplace(dist[e.d],e.d,v);
            }
        }
    }
    return prev;
};

signed main()
{
    int N,M;cin>>N>>M;

    Graph g(N+1);
    vector<int> U(M),V(M);
    for(int i=0;i<M;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        addEdge(g,u,v);
        U[i]=u,V[i]=v;
    }

    using State = tuple<int,int>;
    queue<State> q;
    q.emplace(0,0);
    vector<int> rank(N,-1);
    vector<int> star(N,INF);
    vector<pair<int,int>> vec;
    while(q.size()){
        int u,r;tie(u,r)=q.front();q.pop();
//        cout<<"queue "<<u<<" "<<r<<endl;
        if(star[u]!=INF)continue;
        rank[u]=r; 
        for(auto e:g[u]){
            int v=e.d;
//            cout<<v<<endl;
            if(rank[v]==-1){
                q.emplace(v,r+1);
            }else if(rank[v]%2==r%2){
//                cout<<"star "<<u<<" "<<v<<endl;
                star[u]=star[v]=r;
                vec.emplace_back(u,v);
            }
        }
    }
    for(auto e:vec){
                addEdge(g,e.first,e.second,0);
    }
    for(int i=0;i<N;i++){
        if(star[i]!=INF){
            addEdge(g,N,i,star[i]);
        }
    }
    Array dist;
    dijkstra(g,N,dist);
    int ans=0;
    for(int i=0;i<N;i++){
        ans=max(ans,dist[i]);
    }
    if(ans==INF){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    
//    bool end = false;
//    vector<int> id(N);
//    for(int i=0;i<N;i++){
//        cout<<"rank "<<i<<" "<<rank[i]<<" "<<star[i]<<endl;
//        id[i]=i;
//        if(star[i]){
//            end = true;
//            id[i]=N;
//        }
//    }
//    if(!end){
//        cout<<-1<<endl;
//        return 0;
//    }
//    
//    Graph g2(N+1);
//    for(int i=0;i<M;i++){
//        addEdge(g2,id[U[i]],id[V[i]]);
//    }
//
//    Array dist(N+1);
//    dijkstra(g2,N,dist);
//    int ans=0;
//    for(int i=0;i<=N;i++){
//        if(dist[i]==INF)continue;
//        cout<<i<<" "<<dist[i]<<endl;
//        ans=max(ans,dist[i]);
//    }
//    cout<<ans+1<<endl;

    return 0;
}



