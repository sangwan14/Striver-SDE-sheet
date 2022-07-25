// BFS -> Kahn's Algorithm

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> in_degree(V,0);
	    vector<int> topo;
	    
	    for(int i=0;i<V;i++){
	        for(auto &it : adj[i]){
	            in_degree[it]++;
	        }
	    }
        
        for(int i=0;i<V;i++){
            if(in_degree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto &it : adj[node]){
                in_degree[it]--;
                if(in_degree[it]==0) q.push(it);
            }
        }
	    
	    return topo;
	}
};

// Time Complexity : O(N+E)
// Space Complexity : O(N) [in_degree array] + O(N) [queue]

//DFS

class Solution2
{
	public:
  void dfs(int i, vector<int> &vis, stack<int> &st, vector<int> adj[]){
        vis[i] = 1;
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it, vis, st, adj);
            }
        }
        st.push(i);
    }

  vector<int> topoSort(int V, vector<int> adj[]) 
  {
        vector<int> ans;
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
  }
};

// Time Complexity : O(N+E)
// Space Complexity : O(N) [visited array] + O(N) [recursion]
