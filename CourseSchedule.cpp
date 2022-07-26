//DFS 

class Solution {
public:
     bool dfs(int node, vector<int> adj[], vector<int>& vis){
        vis[node] = 1;
        for(auto &it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis)) return true;
            }
            else if(vis[it]==1){
                return true;
            }
        }
        vis[node]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int> vis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis)) return false; 
            }
        }
        return true;
    }
};

// DFS 2 (using visited and dfsVisited arrays)

class Solution2 {
public:
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

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int> vis(numCourses,0);
        vector<int> dfsVis(numCourses,0);
      
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis)) return false; 
            }
        }
        return true;
    }
};

//Kahn's Algorithm (BFS)

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[u].push_back(v);
        }
        
	queue<int> q; 
        vector<int> indegree(numCourses, 0); 
	
	for(int i = 0;i<numCourses;i++) {
		for(auto it: adj[i]) {
		    indegree[it]++; 
		}
	}

	for(int i = 0;i<numCourses;i++) {
		if(indegree[i] == 0) {
		    q.push(i); 
		}
	}
	    
        int cnt = 0;
	while(!q.empty()) {
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
        
        return cnt == numCourses;
    }
