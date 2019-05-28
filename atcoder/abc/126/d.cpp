#include <bits/stdc++.h>
using namespace std;

struct edge{
	int weight,pair;
};

int N, distant = 0;

void dfs(int a, 
         vector<vector<edge>> &graph,
         vector<int> &ans, 
         vector<int> &color
         ){
         	
	color[a]++;
	
	ans[a] += distant%2;
	
	for( edge k : graph[a] ){
		if( color[k.pair] == 0 ){
			distant += k.weight;
			dfs(k.pair,graph,ans,color);
			distant -= k.weight;
		}
	}
}

int main(){
	cin >> N;
	vector<vector<edge>> graph(N);
	vector<int> ans(N), color(N);
	
	int x,y,z;
	while(cin >> x >> y >> z){
		edge k, l;
		k.pair = x-1; l.pair = y-1;
		k.weight = l.weight = z;
		graph[x-1].push_back(l);
		graph[y-1].push_back(k);
	}
	
	dfs(0,graph,ans,color);
	
	for( int k : ans ){
		cout << k%2 << endl;
	}
}
