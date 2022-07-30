#include<bits/stdc++.h>

using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int low[], int tin[]){
	tin[node] = low[node] = timer++;
	vis[node] = 1;

	for(auto it : adj[node]){
		if(it == parent) continue;

		if(!vis[it]){
			dfs(it,node,vis,adj,low,tin);
			low[node] = min(low[node],low[it]);
			if(low[it] > tin[node]){
				cout << node << " - " << it << endl;
			}
		}
		else{
			low[node] = min(low[node],low[it]);
		}
	}
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

	dfs(1,1,vis,adj,low,tin);
	return 0;
}
