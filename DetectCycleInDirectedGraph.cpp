// DFS

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int> adj[], vector<int>& vis){
        vis[node] = 1;
        for(auto &it:adj[node]){
            if(vis[it]==0){//unvisited node
                if(dfs(it,adj,vis)) return true;
            }
            else if(vis[it]==1){//visited node in the same dfs call
                return true;//cycle is present 
            }
        }
        vis[node]=2;//dfs call completed and no cycle found, never visit this node again
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis)) return true; 
            }
        }
        return false;
    }
};

// DFS 2 (using visited and dfsVisited arrays)

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto &it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,dfsVis)) return true;
            }
            else if(vis[it]==1 and dfsVis[it]==1){
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> dfsVis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsVis)) return true; 
            }
        }
        return false;
    }
};

class Solution3 {
public:
    bool isCyclic(int V, vector<int> adj[]) {
      queue<int> q; 
	    vector<int> indegree(V, 0); 
      
	    for(int i = 0;i<V;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<V;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    
      int cnt = 0;
	    while(!q.empty()){ 
	        int node = q.front(); 
	        q.pop(); 
	        cnt++;
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
      
      return cnt != V;
    }
};
