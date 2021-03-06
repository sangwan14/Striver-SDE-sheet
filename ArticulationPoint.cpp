#include<bits/stdc++.h>

using namespace std;

unordered_set<int> uset;//to avoid repetition of same articulation points

void dfs(int node, int parent, int &timer, vector<int> &vis, vector<int> adj[], int low[], int tin[]){
	tin[node] = low[node] = timer++;
	vis[node] = 1;

	int child = 0;
	for(auto it : adj[node]){
		if(it == parent) continue;

		if(!vis[it]){
			dfs(it,node,timer,vis,adj,low,tin);
			low[node] = min(low[node],low[it]);
			if(low[it] >= tin[node] && parent!=-1 && uset.find(node) == uset.end()){
				uset.insert(node);
				cout << node << endl;
			}
			child++;
		}
		else{
			low[node] = min(low[node],low[it]);
		}
	}
	if(child > 1 and parent == -1) cout << 1 <<endl;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;
	cin >> n >> m;//n = number of nodes, m = Number of edges

	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);//omit this if graph is directed
	}

	vector<int> vis(n+1,0);
	int low[n+1];
	int tin[n+1];

	int timer = 0;
	dfs(1,-1,timer,vis,adj,low,tin);
	return 0;
}
