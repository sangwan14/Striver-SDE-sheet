//BFS

#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
	int shortestPath(int V, vector<int> adj[], int src){
		vector<int> dist(V,INT_MAX);
		queue<int> q;
		q.push(src);
		dist[src] = 0;

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto it : adj[node]){
				if(dist[it] == INT_MAX){
					q.push(it);
					dist[it] = 1 + dist[node];
				}
			}
		}
		
		return dist[V-1];
	}
};

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

	Solution obj;
	cout<<obj.shortestPath(n,adj,3)<<endl;

	return 0;
}

/* Adjacency List

8 10
0 1
0 3
1 3
1 2
3 4
4 5
5 6
2 6
6 7
7 8
6 8

*/
