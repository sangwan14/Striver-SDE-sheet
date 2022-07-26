#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
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
	}

	Solution obj;
	vector<int> topo = obj.topo(n,adj);

	cout<<"Topological Sort: ";
	for(int i=0;i<topo.size();i++) cout<<topo[i]<<" ";
	cout<<endl;

	return 0;
}
